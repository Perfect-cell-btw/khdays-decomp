/* Makes a heap current (the default heap for 0) and returns the previous one; callers bracket
 * work in a scoped arena with two calls. */

extern int gCurrentHeap;

int Heap_SetCurrent(int heap) {
    int head = *(int *)&gCurrentHeap;
    *(int *)&gCurrentHeap = (heap == 0) ? *(int *)((char *)&gCurrentHeap + 4) : heap;
    return head;
}
