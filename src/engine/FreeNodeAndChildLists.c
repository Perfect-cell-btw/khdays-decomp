/* Frees a record node's two child buffers and, unless marked static, the node itself; returns
 * whether there was a node. */

extern void FreeAndClearIfNonNeg();
extern void NNSi_FndFreeFromDefaultHeap();
int FreeNodeAndChildLists(int *param_1)
{
    short *p = (short *)*param_1;
    if (p == 0)
        return 0;
    if (*(int *)(p + 2) != 0)
        FreeAndClearIfNonNeg((int *)(p + 2), (int)*p);
    p = (short *)*param_1;
    if (*(int *)(p + 4) != 0)
        FreeAndClearIfNonNeg((int *)(p + 4), (int)*p);
    if (*(short *)*param_1 >= 0) {
        NNSi_FndFreeFromDefaultHeap((short *)*param_1);
        *param_1 = 0;
    }
    return 1;
}
