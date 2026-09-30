/* Ov000_LeaveTitleForScene -- leave the title and start the next scene.
 *
 * Tears the title down (Ov000_TeardownTitle), publishes the scene block in
 * data_ov000_0205ac3c, then loads and instantiates one of two scenes depending on the
 * transition mode at heap+0xd138: mode 0 goes to the movie player (ov012), anything else
 * to ov011.  The new object is parked at heap+0xd13c and the state machine advances to
 * Ov000_WaitLaunchedSceneThenMenu.
 *
 * Both overlay ids are the ADDRESS of a linker-absolute symbol -- the NitroSDK
 * FS_OVERLAY_ID idiom, which dsd emits into arm9.lcf as `OVERLAY_11_ID = 11;` /
 * `OVERLAY_12_ID = 12;`.  Spelled as plain integers the two pool words disappear and the
 * function comes out 8 bytes short.
 */

#include "nitro/types.h"
#include "game/engine.h"

typedef u32 FSOverlayID;
typedef void *StateFn;

extern u32 OVERLAY_11_ID[1];
extern u32 OVERLAY_12_ID[1];
#define FS_OVERLAY_ID_ov011 ((FSOverlayID)(u32) & (OVERLAY_11_ID))
#define FS_OVERLAY_ID_ov012 ((FSOverlayID)(u32) & (OVERLAY_12_ID))

extern void *NNSi_FndGetCurrentRootHeap(void);
extern void Ov000_TeardownTitle(void);
extern void *InstantiateClass(void *classDesc, int arg);
extern void *data_ov000_0205ac3c;
extern int data_ov011_0205e8a0;
extern int gOv012OpeningSceneClass;
extern void Ov000_WaitLaunchedSceneThenMenu(void);

StateFn Ov000_LeaveTitleForScene(void) {
    char *heap = (char *)NNSi_FndGetCurrentRootHeap();
    void *obj;

    Ov000_TeardownTitle();
    data_ov000_0205ac3c = heap;
    if (*(int *)(heap + 0xd138) == 0) {
        LoadOverlaySync(0, FS_OVERLAY_ID_ov012);
        obj = InstantiateClass((void *)&gOv012OpeningSceneClass, 1);
    } else {
        LoadOverlaySync(0, FS_OVERLAY_ID_ov011);
        obj = InstantiateClass((void *)&data_ov011_0205e8a0, 1);
    }
    *(void **)(heap + 0xd13c) = obj;
    return (StateFn)Ov000_WaitLaunchedSceneThenMenu;
}
