/* Ov107_Region_OnEvent -- refresh a node and forward the event to its parent, ov107. */

#include "game/enemy_common.h"
#include "game/engine.h"

void Ov107_Region_OnEvent(char *node, int event) {
    Ov107_Region_SyncChildVisibility(node);
    DispatchObjectCallbacks(*(void **)(node + 0x104), event);
}
