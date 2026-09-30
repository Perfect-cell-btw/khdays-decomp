/* Constructor for the ov000 sub-scene context: takes the root heap, publishes it, and builds it.
 *
 * The MI_CpuFill8 here MEASURES the context at 0x4bcc -- it clears the whole object, so this is a
 * real size rather than the end of the last field anyone happened to observe. That matters,
 * because Ov000_DrawModeIcon reaches +0x4b04 and +0x4bb8, and both land inside the tail of this
 * same allocation.
 *
 * This context is a DIFFERENT object from the one behind data_ov000_0205ac24 (the 0xd18c scene
 * context). Both are taken from the root heap by their own scene's constructor, so they can share
 * an address while having unrelated layouts; they are kept as separate types for that reason.
 *
 * The four 0x800 buffers are allocated and cleared individually rather than as one 0x2000 block.
 * Both resources are created with id 14 but by two different creators (Msg_OpenContainerAndReadHeader vs
 * Loader_RequestFile), so they are not the same kind of object.
 *
 * Returns the next scene callback, as the rest of this chain does.
 */

#include "nitro/types.h"

typedef void (*OverlayCallback)(void);

typedef struct {
    void *buffers[4];      /* +0x00 */
    u8 pad_0010[0x10];
    int bEnabled;          /* +0x20 */
    u8 pad_0024[4];
    void *resource_0028;   /* +0x28 */
    u8 pad_002c[0x4ad4];
    void *resource_4b00;   /* +0x4b00 */
    u8 pad_4b04[0xc8];     /* +0x4b04 objects reached by Ov000_DrawModeIcon */
} Ov000SubSceneContext;

extern Ov000SubSceneContext *volatile data_ov000_0205ac28;
extern u8 gOv000UiNewgameResPath[];
extern u8 gOv000TextFontEu10AllPath_3[];
extern Ov000SubSceneContext *NNSi_FndGetCurrentRootHeap(void);
extern void MI_CpuFill8(void *dst, int value, u32 size);
extern void *NNS_FndAllocFromDefaultExpHeapEx(u32 size, int alignment);
extern void MIi_CpuClear16(int value, void *dst, u32 size);
extern void *Msg_OpenContainerAndReadHeader(const void *data, int id);
extern void *Loader_RequestFile(const void *data, int id);
extern void Ov000_WaitLoadThenBuildMenu(void);

OverlayCallback Ov000_InitSubScene(void) {
    Ov000SubSceneContext *context = NNSi_FndGetCurrentRootHeap();
    u8 i;

    data_ov000_0205ac28 = context;
    MI_CpuFill8(context, 0, sizeof(Ov000SubSceneContext));
    data_ov000_0205ac28->bEnabled = 1;

    for (i = 0; i < 4; i++) {
        data_ov000_0205ac28->buffers[i] =
            NNS_FndAllocFromDefaultExpHeapEx(0x800, 2);
        MIi_CpuClear16(0, data_ov000_0205ac28->buffers[i], 0x800);
    }

    data_ov000_0205ac28->resource_0028 = Msg_OpenContainerAndReadHeader(gOv000UiNewgameResPath, 14);
    data_ov000_0205ac28->resource_4b00 = Loader_RequestFile(gOv000TextFontEu10AllPath_3, 14);
    return Ov000_WaitLoadThenBuildMenu;
}
