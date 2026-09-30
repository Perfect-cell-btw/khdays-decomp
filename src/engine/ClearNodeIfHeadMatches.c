/* When the node system is active and the node's owner record still points at this node, clears the
 * record. */

extern int gMsgQueue;

void ClearNodeIfHeadMatches(int p) {
    int a, v;
    if (*(int *)&gMsgQueue == 0) return;
    a = *(int *)(p + 0x20);
    v = *(int *)(p + 0x14);
    if (*(int *)(a + 4) == v) *(int *)a = 0;
}
