/* Allocate 0xb4 bytes via CallocInstance, initialise via Ov107_InitContainerNode,
 * return the allocation. */

#include "game/enemy_common.h"

extern int CallocInstance(int size);
int Ov107_ContainerNode_New(void) {
    int r = CallocInstance(0xb4);
    Ov107_InitContainerNode((u16 *)r);
    return r;
}
