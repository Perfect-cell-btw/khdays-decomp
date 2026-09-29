/* Destroys the list objects, then releases the object when its bit 2 flag is set. */

#include "game/engine.h"

extern void Ov008_DestroyAllListObjects(void *context);

typedef struct {
    char pad[0x4a7c];
    unsigned int flags;
} Unk02054364;

void Ov008_DestroyObjectsAndRelease(Unk02054364 *context)
{
    Ov008_DestroyAllListObjects(context);

    if (((context->flags << 29) >> 31) == 1) {
        Obj_Release(context);
        context->flags &= ~4;
    }
}
