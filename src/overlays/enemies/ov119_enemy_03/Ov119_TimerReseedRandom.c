/*
 * ov272 orbit node: the wind-up tick that fires the orbit once its wait timer fills.
 *
 * Each tick adds the scene's frame delta to the node's wait timer. Below 0x1000 the
 * node is still winding up and nothing else happens. On reaching 0x1000 the timer is
 * reset, the orbit is aimed at a fixed start angle (0xffff6216) with a radius of
 * 0x2000 plus a random amount, and the node hands itself to the next state through the
 * shared 0203c634 resolve.
 *
 * The `else { return; }` is load-bearing, not a stylistic choice. Written the other way
 * round -- `if (sum < 0x1000) { return; }` followed by the body -- mwcc pulls the
 * literal-pool load forward and the output diverges at 0x28/0x2c. Keeping the body
 * inside the conditional region and the early exit in the else keeps the load where the
 * ROM has it. This is the same conditional-region-versus-early-exit lever documented in
 * the codegen notes, and here it is the ONLY thing that separates a match from a miss.
 */

#include "game/actor.h"

struct Owner {
    char pad00[0x2c];
    int nFrameDelta;            /* 0x2c */
};

struct AiStateNode {
    struct Owner *pScene;       /* 0x00 */
    Actor *pState;              /* 0x04 */
    char pad08[0x18];
    signed char bSlot;          /* 0x20 */
};

extern int RandNextScaled();
extern void SetIndexedSlot(struct AiStateNode *self, int idx, void *cb);
extern void Ov119_TickOrbitTarget(void);

void Ov119_TimerReseedRandom(struct AiStateNode *self)
{
    Actor *node = self->pState;
    int sum;

    sum = node->mode + self->pScene->nFrameDelta;
    node->mode = sum;

    if (sum >= 0x1000) {
        node->mode = 0;
        node->camera[0] = 0xffff6216;
        node->camera[1] = RandNextScaled(0x1001) + 0x2000;
        SetIndexedSlot(self, self->bSlot, &Ov119_TickOrbitTarget);
    } else {
        return;
    }
}
