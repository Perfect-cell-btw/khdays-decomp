extern void Task_MarkFinished(int obj);
extern void SetSubitemState(int subitem, int a, int b, int c);

// Advance a node timer: accumulate a per-object step into node[2]; once it
// reaches 0x1000, either invoke the terminal handler (sub-state 8) or bump the
// sub-state counter and push the new state to the subitem.
void Ov161_TickTimerAdvanceSubState(int *this)
{
    int node = this[1];
    int acc = *(int *)(node + 8) + *(int *)(*this + 0x2c);
    *(int *)(node + 8) = acc;
    if (acc < 0x1000) {
        return;
    }
    if (*(int *)(node + 0xc) == 8) {
        Task_MarkFinished((int)this);
        return;
    }
    *(int *)(node + 8) = 0;
    *(int *)(node + 0xc) += 1;
    SetSubitemState(*(int *)(node + 4), 4, (short)*(int *)(node + 0xc), 1);
}
