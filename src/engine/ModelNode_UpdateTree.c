/* Per-frame update of a model node and its children (+0x88 list): after the base update
 * (Node_ComposeWorldSrt) a node whose bit 2 (+0x5c) is set drops its +0x70 animation id; otherwise a
 * changed id (+0x70 vs the +0xb0 copy) is pushed to every child. Each child is then updated in
 * turn (RefreshObjectCallbacks). */
#include "nitro/types.h"
typedef struct { int b0 : 1; int b1 : 1; int b2 : 1; } NodeFlags;

extern void Node_ComposeWorldSrt(char *node, int arg);
extern int *List_First(void *list);
extern int *List_Next(void *list);
extern void RefreshObjectCallbacks(int child, int arg);

void ModelNode_UpdateTree(char *node, int arg)
{
    int *it;

    Node_ComposeWorldSrt(node, arg);
    if (!((NodeFlags *)(node + 0x5c))->b2) {
        if (*(u16 *)(node + 0xb0) != *(u16 *)(node + 0x70)) {
            *(u16 *)(node + 0xb0) = *(u16 *)(node + 0x70);
            for (it = List_First(node + 0x88); it != 0; it = List_Next(node + 0x88)) {
                *(u16 *)(*it + 0x70) = *(u16 *)(node + 0x70);
            }
        }
    } else {
        *(u16 *)(node + 0x70) = 0;
    }
    for (it = List_First(node + 0x88); it != 0; it = List_Next(node + 0x88)) {
        RefreshObjectCallbacks(*it, arg);
    }
}
