/* Ov000_PreloadLogoResources -- Scene 1 (boot/logo) resource preload, ov000.
 * Called first thing by the fresh-boot setup (Ov000_FreshBootGfxSetup). Loads the
 * always-present logo resource into scene-heap slot [1], then by region/variant
 * (GetLanguage): variant 1 uses no secondary resource (slot [2] = NULL),
 * variants 2..5 load a region-specific secondary resource into slot [2], and any
 * other value (0 or >5) is a fatal configuration error -> OS_Terminate. */

#include "game/engine.h"

extern void *NNSi_FndGetCurrentRootHeap(void);
extern void *Msg_OpenContainerAndReadHeader(void *desc, int mode);
extern void  OS_Terminate(void);
extern char  gOv000TtlTtlPath[];
extern char  gOv000TtlTtlPath_2[];

void Ov000_PreloadLogoResources(void) {
    void **h = (void **)NNSi_FndGetCurrentRootHeap();
    h[1] = Msg_OpenContainerAndReadHeader(gOv000TtlTtlPath, 0xe);
    switch (GetLanguage()) {
    case 1:
        h[2] = 0;
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        h[2] = Msg_OpenContainerAndReadHeader(gOv000TtlTtlPath_2, 0xe);
        break;
    default:
        OS_Terminate();
    }
}
