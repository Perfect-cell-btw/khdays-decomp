/* Ov008_SwitchMenuTab -- Ov008_SwitchMenuTab (196 B, 7 relocs).
 * Switches the active menu tab from p->curTab to idx. For both the outgoing tab (p->curTab)
 * and the incoming tab (idx) it maps the index to a cell tag (0->0xf0, 1->0xf1, 2->0xf2 for the
 * old tab; 0->0xf3, 1->0xf4, 2->0xf5 for the new tab; anything else keeps the base tag), looks
 * the cell up (Ov008_FindEntryByTag) and re-registers it (Ov008_TagTracker_InvokeCallback). It then retargets
 * the sub-object at p+0xc to p->arr138[idx] (TileSurface_SetCurrentItem) and applies p->arr144[idx]
 * (Ov008_InitDetailPanelKnob), and finally records the new tab in p->curTab.
 *
 * The tag mapping is written so the middle case (==1) sits in an else block: mwcc otherwise
 * predicates it inline and comes out one instruction short per mapping -- the else form forces
 * the ROM's out-of-line branch (cmp/beq to a separate mov) while the last case (==2) predicates. */

#include "nitro/types.h"

typedef struct Ov008TabState {
    int field0;
    int curTab;                 /* 0x04 */
    int field8;
    u8  sub_000c[0x138 - 0xc];  /* 0x0c: sub-object retargeted per tab */
    int arr138[3];              /* 0x138 */
    int arr144[3];              /* 0x144 */
} Ov008TabState;

extern void *Ov008_GetCtxBlock954c(void);
extern void *Ov008_FindEntryByTag(void *ctx, int tag);
extern void  Ov008_TagTracker_InvokeCallback(void *ctx, void *cell);
extern void  TileSurface_SetCurrentItem(void *p, void *target, int update);
extern void  Ov008_InitDetailPanelKnob(Ov008TabState *p, void *value);

void Ov008_SwitchMenuTab(Ov008TabState *p, int idx)
{
    void *ctx = Ov008_GetCtxBlock954c();
    int old = p->curTab;
    int tag;

    tag = 0xf0;
    if (old != 0) {
        if (old != 1) {
            if (old == 2) {
                tag = 0xf2;
            }
        } else {
            tag = 0xf1;
        }
    }
    Ov008_TagTracker_InvokeCallback(ctx, Ov008_FindEntryByTag(ctx, (unsigned short)tag));

    tag = 0xf3;
    if (idx != 0) {
        if (idx != 1) {
            if (idx == 2) {
                tag = 0xf5;
            }
        } else {
            tag = 0xf4;
        }
    }
    Ov008_TagTracker_InvokeCallback(ctx, Ov008_FindEntryByTag(ctx, (unsigned short)tag));

    TileSurface_SetCurrentItem(&p->sub_000c, (void *)p->arr138[idx], 1);
    Ov008_InitDetailPanelKnob(p, (void *)p->arr144[idx]);
    p->curTab = idx;
}
