/* Picks how far down the actor's id list to walk with a d100 -- under 10 stops
   at the head, under 40 at the second entry, otherwise the third -- then fires
   the ov002 effect on whichever id it lands on. A list shorter than the chosen
   depth simply runs out and does nothing. */

#include "game/engine.h"

struct State {
    char *pActor;
};

struct Node {
    void *pScene;
    struct State *pState;
};

extern int *List_First(void *list);
extern void Ov002_SetLocalSlotPair(char *actor, int nId, int a, int b);

void Ov130_FireEffectOnRandomListId(struct Node *node)
{
    struct State *st;
    int *pEntry;
    int nRoll;
    int nDepth;
    long i;

    st = node->pState;
    nRoll = RandNextScaled(100);
    if (nRoll < 10) {
        nDepth = 0;
    } else if (nRoll < 0x28) {
        nDepth = 1;
    } else {
        nDepth = 2;
    }

    pEntry = List_First(st->pActor + 0x398);
    i = 0;
    if (pEntry == 0) {
        return;
    }
    do {
        if (i >= nDepth) {
            Ov002_SetLocalSlotPair(st->pActor, *pEntry, 0, 0x1000);
            return;
        }
        pEntry = List_Next(st->pActor + 0x398);
        i++;
    } while (pEntry != 0);
}
