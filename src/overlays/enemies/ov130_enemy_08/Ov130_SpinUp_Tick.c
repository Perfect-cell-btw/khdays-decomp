/* Spin-up tick. Accumulates scene time; once past 0x198 it seeds the spin
   speeds the first time through and then runs the decay every frame. It leaves
   the state as soon as the owner's busy byte at +0xad clears, kicking the actor
   into motion mode 5 and installing the next state. */

#include "game/ai_task.h"
#include "game/enemy_common.h"

struct State {
    char *pActor;
    char *pOwner;
    char pad08[0x14];
    int nSpeed1c;
    char pad20[0xc];
    int nElapsed2c;
    int nSpin30;
    int nSpin34;
    char pad38[9];
    unsigned char bSeeded41;
};

struct Node {
    AI_TASK_FIELDS(struct State)
};

extern void Ov130_DecaySpinOverElapsed(struct Node *node);
extern void SetIndexedSlot(struct Node *node, int slot, void *next);

extern void Ov130_ClearHiFlagAndAdvance(void);

void Ov130_SpinUp_Tick(struct Node *node)
{
    struct State *st;
    int nElapsed;

    st = node->pState;
    nElapsed = st->nElapsed2c + *(int *)((char *)node->pList + 0x2c);
    st->nElapsed2c = nElapsed;
    if (nElapsed >= 0x198) {
        if (st->bSeeded41 == 0) {
            st->nSpin30 = 0xc00;
            st->nSpeed1c = st->nSpin34 = 0x400;
            st->bSeeded41 = 1;
        }
        Ov130_DecaySpinOverElapsed(node);
    }
    if (*(unsigned char *)(st->pOwner + 0xad) != 0) {
        return;
    }
    Ov107_PostTagUpdate((Actor *)st->pActor, 5, 1);
    SetIndexedSlot(node, node->slot, (void *)Ov130_ClearHiFlagAndAdvance);
}
