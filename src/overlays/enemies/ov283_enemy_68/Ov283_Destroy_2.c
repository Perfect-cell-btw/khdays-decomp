/* Destroys the six part instances and the model instance, then the base object. */

#include "game/engine.h"

extern void Ov107_DestroyObject(int param_1);

struct Elem8 {
    int pad;
    int *ptr;
};

void Ov283_Destroy_2(int param_1) {
    int i;
    for (i = 0; i < 6; i++) {
        DestroyInstance(((struct Elem8 *)param_1)[i + 0x7d].ptr);
    }
    DestroyInstance(*(int **)(param_1 + 0x384));
    Ov107_DestroyObject(param_1);
}
