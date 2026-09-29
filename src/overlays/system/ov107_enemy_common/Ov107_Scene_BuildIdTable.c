/* Rebuilds the id -> node lookup table at +0x48: allocates one pointer per registered id
 * (+0x24) and walks the intrusive list at +4, filing each node under the id in its
 * halfword at +2. */

#include "game/engine.h"

extern void *CallocInstance(unsigned int size);
extern void *List_First(void *list);
extern char *data_ov107_020cbf1c;

void Ov107_Scene_BuildIdTable(void) {
    char *ctx = data_ov107_020cbf1c;
    char *node;
    if (ctx == 0) {
        return;
    }
    *(void **)(ctx + 0x48) = CallocInstance(*(int *)(ctx + 0x24) * 4);
    node = List_First(ctx + 4);
    while (node != 0) {
        char *item = *(char **)node;
        *(char **)(*(char **)(ctx + 0x48) + *(unsigned short *)(item + 2) * 4) = item;
        node = List_Next(ctx + 4);
    }
}
