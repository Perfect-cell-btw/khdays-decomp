/* Steps the mover and, when it produced a new position, moves the actor there. */

#include "game/engine.h"

extern int Mover_Step(void *ptr, void *out, int arg);

void Mover_StepActor(int *ptr, int arg) {
    int out[3];

    if (Mover_Step(ptr, out, arg)) {
        Actor_SetVecAndSyncChild((void *)ptr[0], (VecFx32 *)out);
    }
}
