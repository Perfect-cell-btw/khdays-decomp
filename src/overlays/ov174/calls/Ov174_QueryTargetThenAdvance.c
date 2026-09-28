extern int Ov107_FindNearestObject(int a, int b, int c, int d);
extern void Ov107_PostTagUpdate(int obj, int a, int b);
extern void SetIndexedSlot(int obj, int a, int cb);
extern void Ov174_SteerCircleAttack(void);

// Query the node's target; cache it at node[3]. If none was found, force
// sub-state 2 and advance with no callback; otherwise switch mode 2, clear the
// tracking fields and advance with the follow-up callback.
void Ov174_QueryTargetThenAdvance(int *this, int p2, int p3, int p4)
{
    int *node = (int *)this[1];
    int found = Ov107_FindNearestObject(node[0], 0, p3, p4);
    node[3] = found;
    if (found == 0) {
        *(signed char *)(node[0] + 0x1c7) = 2;
        SetIndexedSlot((int)this, *(signed char *)((int)this + 0x20), 0);
        return;
    }
    Ov107_PostTagUpdate(node[0], 2, 0);
    node[0x12] = 0;
    *(signed char *)((int)node + 0x84) = 0;
    SetIndexedSlot((int)this, *(signed char *)((int)this + 0x20), (int)&Ov174_SteerCircleAttack);
}
