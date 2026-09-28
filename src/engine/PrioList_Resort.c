/* Re-sorts `node` in the priority list: unless it already is the only element at the head, it is
 * unlinked and re-inserted in front of the first element of lower priority (+8), or appended after
 * the last one. The walk starts from the head as it was on entry. */
typedef struct PrioNode {
    struct PrioNode *prev;  /* 0x00 */
    struct PrioNode *next;  /* 0x04 */
    int priority;           /* 0x08 */
} PrioNode;

typedef struct {
    PrioNode *head;
} PrioList;

extern void DList_InsertAfter(PrioList *list, PrioNode *before, PrioNode *node);

void PrioList_Resort(PrioList *list, PrioNode *node)
{
    PrioNode *cur = list->head;
    PrioNode *last = 0;

    if (cur == node && cur->next == 0) {
        return;
    }
    if (cur == node) {
        list->head = node->next;
    }
    if (node->next != 0) {
        node->next->prev = node->prev;
    }
    if (node->prev != 0) {
        node->prev->next = node->next;
    }
    for (; cur != 0; cur = cur->next) {
        if (cur->priority < node->priority) {
            DList_InsertAfter(list, cur, node);
            return;
        }
        last = cur;
    }
    node->prev = last;
    node->next = 0;
    last->next = node;
}
