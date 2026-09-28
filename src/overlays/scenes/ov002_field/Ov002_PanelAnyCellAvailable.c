/* Whether the panel has an available cell: always when field 0x58 is set, otherwise when a column's
 * second flag is set while the enabled mask is non-empty. */

#include "nitro/types.h"

typedef struct {
    u8 bFirst;
    u8 bSecond;
} Ov002PanelCell;

typedef struct {
    u8 pad0000[0x30];
    u8 bColumns;            /* +0x30 */
    u8 bCursorRow;          /* +0x31 */
    Ov002PanelCell aCells[0x227];   /* +0x32 */
    u8 pad0480[0x28];
    int dwEnabledMask;      /* +0x4a8 */
} Ov002PanelSession;

extern Ov002PanelSession *data_ov002_0207f620;

extern int Ov002_GetPanelField0058(void);

int Ov002_PanelAnyCellAvailable(void) {
    Ov002PanelSession *s = data_ov002_0207f620;
    int bAvailable = 0;

    if (s->bColumns != 0) {
        if (Ov002_GetPanelField0058() != 0) {
            bAvailable = 1;
        } else {
            int i;
            int nCount;

            if (s->dwEnabledMask == 0) {
                return bAvailable;
            }
            nCount = s->bColumns;
            for (i = bAvailable; i < nCount; i++) {
                if (s->aCells[i].bSecond != 0) {
                    bAvailable = 1;
                    break;
                }
            }
        }
    }
    return bAvailable;
}
