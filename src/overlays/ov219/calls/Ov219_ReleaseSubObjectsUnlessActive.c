extern void TaskList_FinishByTag(int owner, int instance);
extern void Ov107_AiState_PostTickBase(int obj);

// Release the pending sub-objects unless their sub-state is active: free this[0x3d0]
// (unless sub-state 5) and this[0x3d8] (unless sub-state 3), clearing each slot;
// then run the shared advance handler.
void Ov219_ReleaseSubObjectsUnlessActive(int *this)
{
    if (((signed char *)this)[0x1c6] != 5 && *(int *)((int)this + 0x3d0) != 0) {
        TaskList_FinishByTag(*(int *)((int)this + 0x3c), *(int *)((int)this + 0x3d0));
        *(int *)((int)this + 0x3d0) = 0;
    }
    if (((signed char *)this)[0x1c6] != 3 && *(int *)((int)this + 0x3d8) != 0) {
        TaskList_FinishByTag(*(int *)((int)this + 0x3c), *(int *)((int)this + 0x3d8));
        *(int *)((int)this + 0x3d8) = 0;
    }
    Ov107_AiState_PostTickBase((int)this);
}
