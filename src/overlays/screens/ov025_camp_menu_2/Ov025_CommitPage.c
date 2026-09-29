/*
 * Ov025_CommitPage -- x3 (ov008/...). Commit the built page: unload the source overlay and push the
 * two half-screens. Context at data_02090f04[1]+0x9000. Clear the scroll counter *(u16)+0x9610=0, set
 * the "ready" flag +0x95f4=1, unload the resource overlay at +0x963e, and run the shared prep
 * 0204fc50. For each half whose enable flag (+0x9628 / +0x962c) is set, blit it via 02054390 with the
 * scroll counter (the second half's surface base is +0x4a80). Flush both command lists at +0x9500 and
 * +0x954c (020554e4), finalize (0204ffe4), and return the resulting page handle at +0x9614.
 */

#include "game/engine.h"

extern void Ov025_RunModeCallback(void);
extern void Ov025_UpdateWidgetLayerDefault(int surface, int scroll);
extern void Ov025_TickSelectionWidget(void *cmdlist);
extern void Ov025_FlushDirtyCells(void);
extern int data_ov025_020b5744[];

#define CTXV (*(volatile int *)((char *)data_ov025_020b5744 + 4))

int Ov025_CommitPage(void) {
    *(unsigned short *)(CTXV + 0x9610) = 0;
    *(int *)(CTXV + 0x95f4) = 1;
    func_020362ec((unsigned short *)(CTXV + 0x963e));
    Ov025_RunModeCallback();
    if (*(int *)(data_ov025_020b5744[1] + 0x9628) != 0) {
        Ov025_UpdateWidgetLayerDefault(data_ov025_020b5744[1],
                            *(unsigned short *)(data_ov025_020b5744[1] + 0x9610));
    }
    if (*(int *)(data_ov025_020b5744[1] + 0x962c) != 0) {
        Ov025_UpdateWidgetLayerDefault(data_ov025_020b5744[1] + 0x4a80,
                            *(unsigned short *)(data_ov025_020b5744[1] + 0x9610));
    }
    Ov025_TickSelectionWidget((void *)(data_ov025_020b5744[1] + 0x9500));
    Ov025_TickSelectionWidget((void *)(data_ov025_020b5744[1] + 0x954c));
    Ov025_FlushDirtyCells();
    return *(int *)(data_ov025_020b5744[1] + 0x9614);
}
