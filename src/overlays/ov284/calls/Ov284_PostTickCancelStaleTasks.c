extern void TaskList_FinishByTag(int owner, int instance);
extern void Ov107_AiState_PostTickBase(int obj);

// Release the pending sub-objects at this+0x3b0 (+0x1c and +0xc) unless their
// sub-state (this+0x1c6) matches the held value; then run the shared advance handler.
void Ov284_PostTickCancelStaleTasks(int *this)
{
    if (((signed char *)this)[0x1c6] != 5 && *(int *)(*(int *)((int)this + 0x3b0) + 0x1c) != 0) {
        TaskList_FinishByTag(*(int *)((int)this + 0x3c), *(int *)(*(int *)((int)this + 0x3b0) + 0x1c));
        *(int *)(*(int *)((int)this + 0x3b0) + 0x1c) = 0;
    }
    if (((signed char *)this)[0x1c6] != 6 && *(int *)(*(int *)((int)this + 0x3b0) + 0xc) != 0) {
        TaskList_FinishByTag(*(int *)((int)this + 0x3c), *(int *)(*(int *)((int)this + 0x3b0) + 0xc));
        *(int *)(*(int *)((int)this + 0x3b0) + 0xc) = 0;
    }
    Ov107_AiState_PostTickBase((int)this);
}
