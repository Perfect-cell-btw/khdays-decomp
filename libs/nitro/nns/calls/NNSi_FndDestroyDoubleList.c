/* Unlinks and releases every node of the intrusive doubly linked list. */

#include "game/engine.h"

void NNSi_FndDestroyDoubleList(int *list) {
    int *node = (int *)list[4];
    int *next;
    if (node == list) {
        return;
    }
    do {
        next = (int *)node[0];
        *(int *)(next + 1) = node[1];
        *(int *)node[1] = node[0];
        FreeInstanceMemory(node);
        list[8] = list[8] - 1;
        node = next;
    } while (next != list);
}
