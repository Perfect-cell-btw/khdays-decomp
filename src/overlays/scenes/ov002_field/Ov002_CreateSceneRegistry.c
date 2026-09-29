/* Scene entry: publish the slot-4 descriptor, build the scene registry object
 * from its class template and park it in data_ov002_0207fa20 -- the registry the
 * ov002 accessor family reaches through ((int *)&data_ov002_0207fa20)[1].
 * Reports 1 = entered. */

#include "game/engine.h"

extern int InstantiateClass(const void *cls, int a);

extern char data_ov002_0207f484[];
extern char data_ov002_0207f454[];
extern int data_ov002_0207fa20;

int Ov002_CreateSceneRegistry(void) {
    StoreGlobalArrayEntry(4, (int)data_ov002_0207f484);
    data_ov002_0207fa20 = InstantiateClass(data_ov002_0207f454, 0);
    return 1;
}
