/* Draw list removal: unregisters the two riders (+0x3b4 / +0x3b8) from the list, numbers each
 * rider's +0x22c parts consecutively from 2 into their +4 byte, syncs the riders' hit points
 * (half of this actor's +0x218 max as their max/current, half their current plus one as the
 * +0x3be / +0x3d2 thresholds copied to +0x3bc / +0x3d0) and runs the base removal (020c7b70). */

#include "game/enemy_common.h"

struct ListNode { int item; };
extern struct ListNode *List_First(void *list);
extern struct ListNode *List_Next(void *list);
extern void Ov107_HandleRegionEvent(int self, int list);

void Ov278_RemoveFromDrawList(int self, int list) {
    struct ListNode *part;
    int n;

    Ov107_InitObjectFromSource(list, *(int *)(self + 0x3b4));
    Ov107_InitObjectFromSource(list, *(int *)(self + 0x3b8));
    n = 2;
    for (part = List_First((void *)(*(int *)(self + 0x3b4) + 0x22c)); part != 0;
         part = List_Next((void *)(*(int *)(self + 0x3b4) + 0x22c))) {
        *((unsigned char *)part + 4) = n;
        n++;
    }
    for (part = List_First((void *)(*(int *)(self + 0x3b8) + 0x22c)); part != 0;
         part = List_Next((void *)(*(int *)(self + 0x3b8) + 0x22c))) {
        *((unsigned char *)part + 4) = n;
        n++;
    }
    if (*(int *)(self + 0x3b4) != 0) {
        int rider = *(int *)(self + 0x3b4);
        short v = (short)(*(short *)(self + 0x200 + 0x18) / 2);
        *(short *)(rider + 0x200 + 0x18) = v;
        *(short *)(rider + 0x200 + 0x1a) = v;
        rider = *(int *)(self + 0x3b4);
        *(short *)(rider + 0x300 + 0xbe) = (short)(*(short *)(rider + 0x200 + 0x1a) / 2 + 1);
        *(short *)(rider + 0x300 + 0xbc) = *(short *)(rider + 0x300 + 0xbe);
    }
    if (*(int *)(self + 0x3b8) != 0) {
        int rider = *(int *)(self + 0x3b8);
        short v = (short)(*(short *)(self + 0x200 + 0x18) / 2);
        *(short *)(rider + 0x200 + 0x18) = v;
        *(short *)(rider + 0x200 + 0x1a) = v;
        rider = *(int *)(self + 0x3b8);
        *(short *)(rider + 0x300 + 0xd2) = (short)(*(short *)(rider + 0x200 + 0x1a) / 2 + 1);
        *(short *)(rider + 0x300 + 0xd0) = *(short *)(rider + 0x300 + 0xd2);
    }
    Ov107_HandleRegionEvent(self, list);
}
