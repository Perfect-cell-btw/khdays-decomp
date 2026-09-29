/* Ov000_TitleInit -- Scene 1 (boot/logo) class constructor, ov000.
 * Registered as the constructor in the scene-1 class descriptor @0x0205a9c0;
 * RunClassConstructor calls it as ctor(arg) and stores its return as the object's
 * initial state fn (obj+0x14). Grabs the current root heap as the scene's data
 * block, caches it in data_ov000_0205ac20, runs one-time init (Gfx_Reset2DEngines),
 * then picks the initial state from the launch arg and the boot sub-mode
 * (Ov000_InitSaveSystem): arg 0xfffffffe = respawn/re-enter, arg 0 = default (->2).
 * Fresh-boot path zero-fills the 0x507c-byte block and hands off to
 * Ov000_FreshBootGfxSetup for the real logo setup. Heap word indices:
 *   [0x1311] re-enter flag, [0x1313] boot sub-mode, [0x1317] mode-5 flag. */

#include "game/engine.h"

typedef void *StateFn;

extern void *NNSi_FndGetCurrentRootHeap(void);
extern int   Ov000_InitSaveSystem(void);
extern int   Ov000_BackupAccessGate(int mode);
extern void  MI_CpuFill8(void *dst, int val, int size);
extern StateFn Ov000_FreshBootGfxSetup(int arg);
extern void  Ov000_ShowErrorAndHalt(void);   /* state fn (returned by address) */
extern void  Ov000_HoldTimerState(void);   /* state fn */
extern void *data_ov000_0205ac20;

StateFn Ov000_TitleInit(unsigned int arg) {
    int *heap = (int *)NNSi_FndGetCurrentRootHeap();
    data_ov000_0205ac20 = heap;
    Gfx_Reset2DEngines();

    if (arg == 0xfffffffe) {
        int mode = Ov000_InitSaveSystem();
        switch (mode) {
        case 3:
            heap[0x1313] = 2;
            return (StateFn)Ov000_ShowErrorAndHalt;
        case 5:
            if (Ov000_BackupAccessGate(mode) == 0) {
                heap[0x1313] = 2;
                return (StateFn)Ov000_ShowErrorAndHalt;
            }
            break;
        }
    } else {
        int mode = Ov000_InitSaveSystem();
        if (arg != 0 || mode == 3) {
            if (arg == 0) {
                arg = 2;
            }
            heap[0x1313] = arg;
            return (StateFn)Ov000_ShowErrorAndHalt;
        }
        if (mode == 5) {
            heap[0x1317] = 1;
            return (StateFn)Ov000_HoldTimerState;
        }
    }

    MI_CpuFill8(heap, 0, 0x507c);
    if (arg == 0xfffffffe) {
        heap[0x1311] = 1;
    }
    return Ov000_FreshBootGfxSetup(0);
}
