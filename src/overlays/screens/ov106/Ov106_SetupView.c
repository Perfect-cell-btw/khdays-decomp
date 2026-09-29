/* Set up the ov106 scene's view: the data_ov106_020b8ad0 resource loads (mode 0xe) into +0x8b48, the
 * +0x8b4c camera initialises and its projection is built into +0x8b84, the scene layout runs
 * (020b782c), the resource is released and the scene widgets reset (020b78bc). */

#include "game/engine.h"

extern char *data_ov106_020b8b60;
extern char data_ov106_020b8ad0[];
extern void *Msg_OpenContainerAndReadHeader(const void *descriptor, int mode);
extern void Camera_BuildProjectionMtx(int a, int b, int c, int d, int e, int scale, void *projOut);
extern void Ov106_LayoutMarkerWidget(void);
extern void Ov106_ResetTargetWidget(void);

void Ov106_SetupView(void)
{
    *(void **)(data_ov106_020b8b60 + 0x8b48) = Msg_OpenContainerAndReadHeader(data_ov106_020b8ad0, 0xe);
    Projection_LoadDefaults(data_ov106_020b8b60 + 0x8b4c);
    Camera_BuildProjectionMtx(*(int *)(data_ov106_020b8b60 + 0x8b4c), *(int *)(data_ov106_020b8b60 + 0x8b50),
                  *(int *)(data_ov106_020b8b60 + 0x8b54), *(int *)(data_ov106_020b8b60 + 0x8b58),
                  *(int *)(data_ov106_020b8b60 + 0x8b5c), 0x1000, data_ov106_020b8b60 + 0x8b84);
    Ov106_LayoutMarkerWidget();
    ZeroHalfThenFree(*(void **)(data_ov106_020b8b60 + 0x8b48));
    Ov106_ResetTargetWidget();
}
