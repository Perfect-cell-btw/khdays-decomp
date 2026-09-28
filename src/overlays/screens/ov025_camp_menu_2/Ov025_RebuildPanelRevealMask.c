
/* The 3-page x 8-row x 5-column panel grid also used by ov000's tally subsystem. */

#include "nitro/types.h"

typedef struct Ov008PanelRevealCtx {
    u8  pad_0000[0x58];
    int pendingA;
    int pendingB;
    u8  pad_0060[0x1e74 - 0x60];
    int revealCount;
    u8  pad_1e78[0x10];
    u8  grid[3][8][5];
    u8  gridShadow[0x78];
} Ov008PanelRevealCtx;

extern void MI_CpuCopy8(void *src, void *dst, unsigned int n);
extern int  Ov025_GetContext(void);
extern int  Ov025_FindEntryById(int ctx, int id);
extern void Ov025_SetEntrySlotsVisible(int ctx, int entry, int visible);

/* Rebuild the reveal mask: the first revealCount cells (walking pages, then rows, then
 * columns) stay 0 = revealed, the rest become 0xff = hidden; mirror the mask, then hide
 * shop entries 0x65..0x78 and clear the two pending words.
 * Declaration order (p,r,c before n, even though n is assigned first) is load-bearing:
 * it is what makes mwcc colour the counters ip/lr/r4/r5 the way retail did. */
void Ov025_RebuildPanelRevealMask(Ov008PanelRevealCtx *self) {
    int p;
    int r;
    int c;
    int n;
    int ctx;
    int id;

    n = 0;
    for (p = 0; p < 3; p++) {
        for (r = 0; r < 8; r++) {
            for (c = 0; c < 5; c++) {
                self->grid[p][r][c] = n < self->revealCount ? 0 : 0xff;
                n++;
            }
        }
    }
    MI_CpuCopy8(self->grid, self->gridShadow, 0x78);
    ctx = Ov025_GetContext();
    for (id = 0x65; id <= 0x78; id++) {
        Ov025_SetEntrySlotsVisible(ctx, Ov025_FindEntryById(ctx, id), 0);
    }
    self->pendingA = 0;
    self->pendingB = 0;
}
