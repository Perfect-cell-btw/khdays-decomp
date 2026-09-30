/* Destroys the model, the child selector and the three attached instances, frees the table, then
 * the base object. */

#include "game/enemy_common.h"

extern int DestroyInstance();
extern int FreeInstanceMemory();
extern int Ov107_DestroyObject();

struct E { int a; int b; };

void Ov182_Destroy(int *p) {
    int i;
    DestroyInstance(p[0x384 / 4]);
    Ov107_ActionResource_Destroy((char *)(p[0x390 / 4]));
    for (i = 0; i < 3; i++) {
        DestroyInstance(((struct E *)p[0x398 / 4])[i].a);
    }
    FreeInstanceMemory(p[0x398 / 4]);
    Ov107_DestroyObject(p);
}
