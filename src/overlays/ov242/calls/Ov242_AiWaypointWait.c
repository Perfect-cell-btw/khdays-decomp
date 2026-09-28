/* Counts the waypoint delay down; then installs the next-waypoint step. */

extern void SetIndexedSlot();
extern void Ov242_NextWaypoint(void);
void Ov242_AiWaypointWait(int node) {
    int *a = *(int **)node;
    int *b = *(int **)(node + 4);
    int diff = b[0xb] - a[0xb];
    b[0xb] = diff;
    if (diff > 0) return;
    SetIndexedSlot(node, *(signed char *)(node + 0x20), Ov242_NextWaypoint);
}
