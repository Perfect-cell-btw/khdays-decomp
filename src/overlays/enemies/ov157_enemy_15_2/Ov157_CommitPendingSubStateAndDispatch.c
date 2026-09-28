extern void SetIndexedSlot(int obj, int slot, int cb);
extern void Ov157_ConfigHw60CopyVec3ConstToCThenAdvance(void);
extern void Ov157_DashEntry(void);

// If a sub-state transition is pending (node[0][0x1c7] != -1), commit it into the
// current sub-state (0x1c6), clear the busy flag (node[0x24] bit0), install the
// matching state callback (for sub-state 0 or 1), and clear the pending slot.
void Ov157_CommitPendingSubStateAndDispatch(int *this)
{
    int node = this[1];
    signed char pending = *(signed char *)(*(int *)node + 0x1c7);
    if (pending == -1) {
        return;
    }
    *(signed char *)(*(int *)node + 0x1c6) = pending;
    *(unsigned char *)(node + 0x24) &= ~1;
    switch (*(signed char *)(*(int *)node + 0x1c6)) {
    case 0:
        SetIndexedSlot((int)this, 1, (int)&Ov157_ConfigHw60CopyVec3ConstToCThenAdvance);
        break;
    case 1:
        SetIndexedSlot((int)this, 1, (int)&Ov157_DashEntry);
        break;
    }
    *(signed char *)(*(int *)node + 0x1c7) = -1;
}
