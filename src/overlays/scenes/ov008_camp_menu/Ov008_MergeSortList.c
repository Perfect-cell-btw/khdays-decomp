/* Sorts an NNS FND list with a merge sort: splits it at the middle (slow/fast walk), sorts both
 * halves and merges them with the comparison. */

#include "nitro/types.h"

typedef struct NNSFndList {
    void *head;
    void *tail;
    u16 count;
    u16 linkOffset;
} NNSFndList;

typedef int (*NNSFndCompare)(void *left, void *right);

extern void *NNS_FndGetNextListObject(NNSFndList *list, void *object);
extern void Ov008_MergeSortedLists(NNSFndList *destination,
                                NNSFndList *leftList,
                                NNSFndList *rightList,
                                NNSFndCompare compare);

void Ov008_MergeSortList(NNSFndList *list, NNSFndCompare compare)
{
    void *slow;
    void *fast;
    u16 leftCount;
    NNSFndList leftList;
    NNSFndList rightList;

    slow = NNS_FndGetNextListObject(list, 0);
    if (slow == 0) {
        return;
    }
    fast = NNS_FndGetNextListObject(list, slow);
    if (fast == 0) {
        return;
    }

    fast = NNS_FndGetNextListObject(list, fast);
    leftCount = 1;
    while (fast != 0) {
        slow = NNS_FndGetNextListObject(list, slow);
        fast = NNS_FndGetNextListObject(list, fast);
        if (fast != 0) {
            fast = NNS_FndGetNextListObject(list, fast);
        }
        leftCount++;
    }

    leftList = *list;
    rightList = *list;

    rightList.head = NNS_FndGetNextListObject(list, slow);
    *(void **)((char *)rightList.head + rightList.linkOffset) = 0;
    rightList.count = (u16)(list->count - leftCount);
    leftList.tail = slow;
    *(void **)((char *)slow + leftList.linkOffset + 4) = 0;
    leftList.count = leftCount;

    Ov008_MergeSortList(&leftList, compare);
    Ov008_MergeSortList(&rightList, compare);

    list->head = 0;
    list->tail = 0;
    list->count = 0;
    Ov008_MergeSortedLists(list, &leftList, &rightList, compare);
}
