/* Push one panel slot's state.
 *
 * Forwards the slot and state to the slot bookkeeping, re-pushes the node's own
 * kind together with the caller's value, and invokes the node callback. Only
 * then, and only when the state is 0 or lies between 3 and 6, the node's value
 * and kind are mirrored onto the widget the context holds for tag 2.
 *
 * nState is a state index with ranges, not a flag -- which is why the caller
 * has to select it between two named constants rather than a literal 0 and 1.
 *
 * Two codegen notes. The two out-of-range tests are explicit returns, so the
 * ROM predicates the epilogue instead of branching to a shared tail. And the
 * tag-2 handle is fetched in its own statement: left inside the argument list
 * it is evaluated after the node loads, and the ROM does it first.
 */
#include "nitro/types.h"

typedef struct {
    u8 pad0000[2];
    short nValue;           /* +0x02 */
    short nKind;            /* +0x04 */
} Ov002TagTrackerNode;

typedef struct {
    u8 pad0000[0x620];
    Ov002TagTrackerNode *aNodes[8];   /* +0x620, indexed by slot */
} Ov002PanelSession;

extern Ov002PanelSession *data_ov002_0207f620;

extern void Ov002_PanelApplySlotState(int nSlot, int nState);
extern void Ov002_PositionSubDcHandle_2(Ov002TagTrackerNode *pNode, short nValue,
                                short nKind);
extern void Ov002_Ctx_InvokeTagTrackerCallback(Ov002TagTrackerNode *pNode);
extern int Ov002_Ctx_FindActiveEntryByTag(int nTag);
extern void Ov002_PositionSubDcHandle_4(int nHandle, short nValue, short nKind);

void Ov002_PanelPushSlotState(int nSlot, int nState, int nValue) {
    Ov002PanelSession *s = data_ov002_0207f620;
    int nHandle;

    Ov002_PanelApplySlotState(nSlot, nState);
    Ov002_PositionSubDcHandle_2(s->aNodes[nSlot], nValue,
                        s->aNodes[nSlot]->nKind);
    Ov002_Ctx_InvokeTagTrackerCallback(s->aNodes[nSlot]);

    if (nState != 0) {
        if (nState < 3) {
            return;
        }
        if (nState > 6) {
            return;
        }
    }
    nHandle = Ov002_Ctx_FindActiveEntryByTag(2);
    Ov002_PositionSubDcHandle_4(nHandle, s->aNodes[nSlot]->nValue,
                        s->aNodes[nSlot]->nKind);
}
