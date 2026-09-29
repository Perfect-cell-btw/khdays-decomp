/* Allocate a 0x120-byte object, initialise it via 020c0dd0 and return it. */

#include "game/enemy_common.h"

extern int CallocInstance(int a);
int Ov107_CreateMovementNode(void) {
    int obj = CallocInstance(0x120);
    Ov107_InitMovementNode((u16 *)obj);
    return obj;
}
