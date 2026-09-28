/* Counts the waypoint delay down; then installs the next-waypoint step. */

extern void SetIndexedSlot(void *a, int b, void *cb);
extern void Ov243_NextWaypoint(void);

void Ov243_AiWaypointWaitB(char *a) {
    char *p = *(char **)a;
    char *q = *(char **)(a + 4);
    int delta = *(int *)(q + 0x2c) - *(int *)(p + 0x2c);
    *(int *)(q + 0x2c) = delta;
    if (delta > 0) return;
    SetIndexedSlot(a, *(signed char *)(a + 0x20), Ov243_NextWaypoint);
}
