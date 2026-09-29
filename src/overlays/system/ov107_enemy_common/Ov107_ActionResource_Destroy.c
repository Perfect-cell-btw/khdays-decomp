/* Ov107_ActionResource_Destroy -- update the node's child widget then itself, ov107. */

#include "game/engine.h"

void Ov107_ActionResource_Destroy(char *node) {
    DestroyInstance(*(void **)(node + 0x3c));
    FreeInstanceMemory(node);
}
