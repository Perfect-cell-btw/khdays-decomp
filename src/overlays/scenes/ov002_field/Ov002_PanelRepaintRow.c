/* Repaint one panel row.
 *
 * The cell at nIndex drives everything: when its first byte is 0xff, or the
 * index is 0x0f or above, the row falls back to the blank glyph block with no
 * style; otherwise the block is nIndex*16 + 0x130 and the style comes from the
 * group lookup on that same byte, unless the panel state is zero.
 *
 * The label is then written with palette 0xf or 0xe according to bEnabled, and
 * the style is translated into a slot state through one of two four-entry
 * tables -- which one depends on the alignment, and a styleless row falls back
 * to 0 or 1 respectively. Finally, a live cell repaints its second byte as the
 * row's value.
 *
 * The rebuild calls this twice in a row, for the row it leaves and the row it
 * enters.
 *
 * Two codegen notes. The condition is written positively, with the fallback in
 * the else, because that is the order the ROM lays the blocks out. And the
 * session pointer needs both a conversion in its initialiser and its
 * declaration placed after the tile: either alone leaves it one register away
 * from the ROM's choice, and only the two together land on it.
 */

#include "nitro/types.h"

typedef struct {
    u8 bFirst;
    u8 bSecond;
} Ov002PanelCell;

typedef struct {
    u8 pad0000[0x10];
    int nState;                     /* +0x10 */
    u8 pad0014[0x1e];
    Ov002PanelCell aCells[0x227];   /* +0x32 */
} Ov002PanelSession;

extern void *data_ov002_0207f620;
extern int data_ov002_0207de70[];
extern int data_ov002_0207de80[];

extern int Ov002_PanelFindGroupSlot(int nGroup, int nKey);
extern void Ov002_PanelWriteSlotLabel(int nSlot, int nColumn, int nTile,
                                int nPalette, int bRightAlign);
extern void Ov002_PanelPushSlotState(int nSlot, int nState, int nValue);
extern void Ov002_Panel_DrawCounterAlt(int nSlot, int nValue, int nColumn,
                                int bRightAlign);
extern void Ov002_SelectEntry(int nItemId);

void Ov002_PanelRepaintRow(int nIndex, int nSlot, int nColumn, int bEnabled,
                         int bRightAlign) {
    u16 nPalette;
    u16 nTile;
    Ov002PanelSession *s;
    int nStyle;
    int nSlotState;

    s = (Ov002PanelSession *)data_ov002_0207f620;

    if (s->aCells[nIndex].bFirst != 0xff && nIndex < 0xf) {
        nTile = nIndex * 16 + 0x130;
        if (s->nState == 0) {
            nStyle = -1;
        } else {
            nStyle = Ov002_PanelFindGroupSlot(8, s->aCells[nIndex].bFirst);
        }
    } else {
        nTile = 0x3d0;
        nStyle = -1;
    }

    nPalette = bEnabled ? 0xf : 0xe;
    Ov002_PanelWriteSlotLabel(nSlot, nColumn, nTile, nPalette, bRightAlign);

    if (bRightAlign != 0) {
        nSlotState = nStyle >= 0 ? data_ov002_0207de70[nStyle] : 0;
    } else {
        nSlotState = nStyle >= 0 ? data_ov002_0207de80[nStyle] : 1;
    }
    Ov002_PanelPushSlotState(nSlot, nSlotState, nColumn);

    if (s->aCells[nIndex].bFirst != 0xff && nIndex < 0xf) {
        Ov002_Panel_DrawCounterAlt(nSlot, s->aCells[nIndex].bSecond, nColumn,
                            bRightAlign);
    }
    Ov002_SelectEntry(9);
    Ov002_SelectEntry(0xb);
}
