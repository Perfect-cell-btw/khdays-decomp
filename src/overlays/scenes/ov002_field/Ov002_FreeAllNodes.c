#include "game/engine.h"

extern void *NNS_FndGetNextListObject(void *list, void *obj);
extern void Ov002_RemoveAndFreeNode(void *obj);

extern int data_ov002_0207f60c;
extern char data_ov002_0207e8a8[];

/* Empty the node list at ctx+0xa4: walk it, and hand every node to
 * Ov002_RemoveAndFreeNode, which unlinks it from that same list and frees it.
 * `next` is fetched BEFORE the node is destroyed -- reading it afterwards would
 * be a use-after-free, which is why the loop carries two pointers. */
void Ov002_FreeAllNodes(void) {
    char *ctx = *(char **)&data_ov002_0207f60c;
    void *node;
    void *next;

    node = NNS_FndGetNextListObject(ctx + 0xa4, 0);
    if (node != 0) {
        do {
            next = NNS_FndGetNextListObject(ctx + 0xa4, node);
            Ov002_RemoveAndFreeNode(node);
            node = next;
        } while (next != 0);
    }
    VBlank_UnregisterCallback(1, data_ov002_0207e8a8);
}
