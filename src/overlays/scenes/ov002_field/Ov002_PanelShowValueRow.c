/* Show or hide one value row of the panel, as a pair of tag-tracker nodes.
 *
 * While the session state is non-zero both nodes are simply disarmed and
 * nothing else happens. Otherwise the label node is armed, and the value node
 * is filled with nValue under kind 0x11 and armed only when the caller says the
 * row is on screen -- bVisible is both the condition and the armed state it
 * ends up in. bRefresh adds the node reset to each node the call touches.
 *
 * nValue reaches the setter sign-extended from 16 bits, which is why the setter
 * declares it short: the truncation belongs to the callee prototype, not to a
 * cast here. All three list classes of the panel repaint converge on this call.
 */

#include "nitro/types.h"

typedef struct {
    u8 pad0000[0x10];
    int nState;             /* +0x10 */
} Ov002PanelSession;

extern Ov002PanelSession *data_ov002_0207f620;

extern void Ov002_Ctx_SetTagTrackerNodeArmed_5(int nHandle, int bArmed);
extern void Ov002_ForwardToSubDc_3(int nHandle);
extern void Ov002_PositionSubDcHandle_4(int nHandle, short nValue, int nKind);

void Ov002_PanelShowValueRow(int nTop, int nMain, int nValue, int bRefresh,
                         int bVisible) {
    Ov002PanelSession *s = data_ov002_0207f620;

    if (s->nState != 0) {
        Ov002_Ctx_SetTagTrackerNodeArmed_5(nTop, 0);
        Ov002_Ctx_SetTagTrackerNodeArmed_5(nMain, 0);
        return;
    }
    if (bRefresh != 0) {
        Ov002_ForwardToSubDc_3(nTop);
    }
    Ov002_Ctx_SetTagTrackerNodeArmed_5(nTop, 1);
    if (bVisible != 0) {
        Ov002_PositionSubDcHandle_4(nMain, nValue, 0x11);
        if (bRefresh != 0) {
            Ov002_ForwardToSubDc_3(nMain);
        }
    }
    Ov002_Ctx_SetTagTrackerNodeArmed_5(nMain, bVisible);
}
