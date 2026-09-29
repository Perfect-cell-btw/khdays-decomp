/* Makes a heap current (the default heap for 0) and returns the previous one; callers bracket
 * work in a scoped arena with two calls. */

extern int data_0204c028;

int Heap_SetCurrent(int heap) {
    int head = *(int *)&data_0204c028;
    *(int *)&data_0204c028 = (heap == 0) ? *(int *)((char *)&data_0204c028 + 4) : heap;
    return head;
}
