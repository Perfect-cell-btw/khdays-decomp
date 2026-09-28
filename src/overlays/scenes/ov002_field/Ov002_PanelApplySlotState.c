/* Apply a state descriptor to one panel slot's tag-tracker node.
 *
 * Resolves the slot's node and the descriptor the state selects, then tail
 * calls the context method. The whole body is a leaf tail call, so there is no
 * frame at all: mwcc loads the target from the literal pool and leaves through
 * bx rather than branching directly. The target is itself ARM, so that
 * indirection is the interworking calling convention, not a mode switch.
 *
 * This is the first call of the slot state push.
 */
#include "nitro/types.h"

typedef struct {
    u8 pad0000[2];
    short nValue;           /* +0x02 */
    short nKind;            /* +0x04 */
} Ov002TagTrackerNode;

typedef struct {
    u8 pad0000[0x5f4];
    int aSlotStates[11];             /* +0x5f4, indexed by slot state */
    Ov002TagTrackerNode *aNodes[8];  /* +0x620, indexed by slot */
} Ov002PanelSession;

extern Ov002PanelSession *data_ov002_0207f620;

extern void Ov002_Ctx_SetTagTrackerNodeArmed(Ov002TagTrackerNode *pNode, int nState);

void Ov002_PanelApplySlotState(int nSlot, int nState) {
    Ov002PanelSession *s = data_ov002_0207f620;

    Ov002_Ctx_SetTagTrackerNodeArmed(s->aNodes[nSlot], s->aSlotStates[nState]);
}
