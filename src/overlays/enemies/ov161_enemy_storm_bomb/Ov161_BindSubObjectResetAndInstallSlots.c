extern void SetSubitemState(int subitem, int a, int b, int c);
extern void SetIndexedSlot(int obj, int idx, int cb);
extern void Ov161_ConfigureSubObjectTwiceThenAdvance(void);
extern void Ov161_CopyBoundBlock44(void);

// Resolve the linked sub-object (node[0][0x3c4][0x28]) into node[1], clear its
// active bit (obj[0x5c] bit1), reset its sub-state to 2 then 0, and install the
// two follow-up callbacks in slots 1 and 2.
void Ov161_BindSubObjectResetAndInstallSlots(int *this)
{
    int node = this[1];
    int obj = *(int *)(*(int *)(*(int *)node + 0x3c4) + 0x28);
    *(int *)(node + 4) = obj;
    *(unsigned int *)(obj + 0x5c) &= ~2u;
    SetSubitemState(*(int *)(node + 4), 2, 0, 0);
    SetSubitemState(*(int *)(node + 4), 0, 0, 0);
    SetIndexedSlot((int)this, 1, (int)&Ov161_ConfigureSubObjectTwiceThenAdvance);
    SetIndexedSlot((int)this, 2, (int)&Ov161_CopyBoundBlock44);
}
