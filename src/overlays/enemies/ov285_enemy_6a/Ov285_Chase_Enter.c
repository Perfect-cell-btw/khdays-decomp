/* Chase state entry. Acquires a target; with none it asks the actor for state 2 and clears the
 * slot. Otherwise it resets the phase, kicks the actor's motion, rolls a chase duration of 0x1000
 * plus rand(0x3001), and installs the chase tick. */

#include "nitro/types.h"
#include "game/ai_task.h"
#include "game/enemy_common.h"
#include "game/engine.h"

struct State {
    char *pActor;
    char pad04[0x14];
    void *pTarget;      /* 0x18 */
    char pad1c[0xc];
    int nPhase28;       /* 0x28 */
    int nTimer2c;       /* 0x2c */
};

struct Node {
    AI_TASK_FIELDS(struct State)
};

extern void *Ov107_FindNearestObject(char *actor, int mode);
extern void SetIndexedSlot(struct Node *node, int slot, void *next);

extern void Ov285_Chase_Tick(void);

void Ov285_Chase_Enter(struct Node *node)
{
    struct State *st;
    void *pTarget;

    st = node->pState;
    pTarget = Ov107_FindNearestObject(st->pActor, 0);
    st->pTarget = pTarget;
    if (pTarget == 0) {
        *(u8 *)(st->pActor + 0x1c7) = 2;
        SetIndexedSlot(node, node->slot, 0);
        return;
    }
    st->nPhase28 = 0;
    Ov107_PostTagUpdate((Actor *)st->pActor, 1, 1);
    st->nTimer2c = RandNextScaled(0x3001) + 0x1000;
    SetIndexedSlot(node, node->slot, (void *)Ov285_Chase_Tick);
}
