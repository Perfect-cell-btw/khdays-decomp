/* Destroys the model, the child selector and the five attached instances, frees the table, then the
 * base object. */

#include "game/enemy_common.h"

extern int DestroyInstance();
extern int FreeInstanceMemory();
extern int Ov107_DestroyObject();

struct Entry {
    void *ptr;
    int pad;
};

struct Obj {
    char pad0[0x384];
    void *field_384;
    char pad1[0x3c4 - 0x384 - 4];
    struct Entry *field_3c4;
    void *field_3c8;
};

int Ov132_Destroy(struct Obj *self) {
    int i;
    DestroyInstance(self->field_384);
    Ov107_ActionResource_Destroy(self->field_3c8);
    for (i = 0; i < 5; i++) {
        DestroyInstance(self->field_3c4[i].ptr);
    }
    FreeInstanceMemory(self->field_3c4);
    return Ov107_DestroyObject(self);
}
