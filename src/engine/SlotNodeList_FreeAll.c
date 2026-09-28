/* Frees every node (and its buffers) of the list at +0x4620. */

extern void SlotNode_FreeBuffers(void *node);
extern void NNSi_FndFreeFromDefaultHeap(void *p);

typedef struct Node02032364 {
    char _0[0x5c];
    struct Node02032364 *next;
} Node02032364;

void SlotNodeList_FreeAll(void *p) {
    Node02032364 *node = *(Node02032364 **)((char *)p + 0x4620);
    Node02032364 *next;
    if (node == 0) return;
    do {
        next = node->next;
        SlotNode_FreeBuffers(node);
        NNSi_FndFreeFromDefaultHeap(node);
        node = next;
    } while (next != 0);
}
