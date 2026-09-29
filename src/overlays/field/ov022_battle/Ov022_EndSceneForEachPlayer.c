/* Scene teardown: commit the open document and hand back the next scene step, or
 * null if Ov002_StepRosterSlotRelease(-1) says there is nothing to commit.
 *
 * data_0204c240 bit 2 (the same boot-mode gate ov002 reads) selects between one
 * commit for the whole document (index -1) and one commit per connected peer.
 *
 * The main path lives INSIDE the guard so that its `return 0` shares the tail
 * block the ROM branches to at +0xbc; written as an early `return 0` mwcc emits a
 * second epilogue instead. */

#include "game/engine.h"

typedef struct {
    char pad00[0x30];
    int nHandle;               /* +0x30 */
} Ov022Session;

extern Ov022Session *data_ov022_020b2e60;
extern unsigned char data_0204c240;

extern void Ov022_UpdateCameraAndViews(int a);
extern int Ov002_StepRosterSlotRelease(int index);
extern int Ov002_GetCodeOwnerSlot(int handle);
extern void Ov002_FormatWorldPath(int handle, void *out);
extern int func_ov022_020882f8(void);
extern void Ov002_WriteSessionMarker(int index, int a, int *out, int d, void *buf, int f);
extern void Ov002_RefreshSessionMarkerDestinations(void);
extern void Ov002_SetRosterSlotTargets(int a, int b);
extern void Ov022_PollBattleEntry(void);

void *Ov022_EndSceneForEachPlayer(void) {
    int out[3];
    int buf[4];
    int a;
    int i;

    Ov022_UpdateCameraAndViews(0);
    if (Ov002_StepRosterSlotRelease(-1) == 1) {
        out[0] = 0;
        out[1] = 0;
        out[2] = 0;
        a = Ov002_GetCodeOwnerSlot(data_ov022_020b2e60->nHandle);
        Ov002_FormatWorldPath(data_ov022_020b2e60->nHandle, buf);
        if ((data_0204c240 & 4) == 0) {
            for (i = 0; i < func_ov022_020882f8(); i++) {
                if (i != QueryActiveStateOrDelegate()) {
                    Ov002_StepRosterSlotRelease(i);
                }
            }
            for (i = 0; i < func_ov022_020882f8(); i++) {
                Ov002_WriteSessionMarker(i, a, out, 0, buf, 0);
            }
            Ov002_RefreshSessionMarkerDestinations();
        } else {
            Ov002_WriteSessionMarker(-1, a, out, 0, buf, 0);
        }
        Ov002_SetRosterSlotTargets(0, -1);
        data_ov022_020b2e60->nHandle = 0;
        SoundMgr_SetListenersEnabled(0);
        return (void *)&Ov022_PollBattleEntry;
    }
    return 0;
}
