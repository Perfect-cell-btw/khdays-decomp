/* Destroys the model instances, then the base object. */

#include "game/engine.h"

extern void Ov107_DestroyObject(void *);

struct S {
    char pad[0x384];
    void *f384;
    char pad2[0x3bc - 0x384 - 4];
    void *f3bc;
};

void Ov234_Destroy(struct S *p)
{
    DestroyInstance(p->f384);
    DestroyInstance(p->f3bc);
    Ov107_DestroyObject(p);
}
