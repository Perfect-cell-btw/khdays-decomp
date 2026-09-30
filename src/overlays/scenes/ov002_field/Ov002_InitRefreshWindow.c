/* Initialize the refresh-window subsystem and register its named task. */

#include "nitro/types.h"

typedef struct Ov002RefreshWindowState {
    unsigned int uFlags;
    int nScale;
    int fxMetric;
    u8 gap000c[0x34];
    int nLatch;
    u8 bStatus;
} Ov002RefreshWindowState;

extern Ov002RefreshWindowState *data_ov002_0207f600;
extern int gOv002RefreshWndName;

extern int GetMasterBrightnessSub(void);
extern void Ov002_DrawFlatRect(int nX, int nY, int nWidth,
                                int nHeight, int nMode);
extern void Ov002_RefreshWindowCallback(void);
extern void RegisterNamedTask(int nPriority, void *pName,
                          void (*pCallback)(void));

void Ov002_InitRefreshWindow(void)
{
    data_ov002_0207f600->fxMetric = GetMasterBrightnessSub() << 12;
    data_ov002_0207f600->nScale = 0x100;
    data_ov002_0207f600->uFlags |= 1;
    data_ov002_0207f600->uFlags &= ~0x10;
    data_ov002_0207f600->nLatch = 0;
    data_ov002_0207f600->bStatus = 0;
    Ov002_DrawFlatRect(0, 0, 0x100, 0xc0, 0);
    RegisterNamedTask(1, &gOv002RefreshWndName, Ov002_RefreshWindowCallback);
}
