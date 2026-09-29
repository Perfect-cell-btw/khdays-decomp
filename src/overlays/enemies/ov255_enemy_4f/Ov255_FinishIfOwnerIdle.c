/* Marks the task finished once the owner's flag is clear. */

#include "game/engine.h"

struct sub { unsigned char pad[0xad]; unsigned char flag; };
struct outer { int x; struct sub **p; };

void Ov255_FinishIfOwnerIdle(struct outer *a) {
    if ((*a->p)->flag == 0) {
        Task_MarkFinished(a);
    }
}
