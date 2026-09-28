extern int Obj_IsIdFree();
extern void TailForwardTrackEntry_2();
int DispatchTrackEntryIfReady(int param_1, unsigned int param_2)
{
    if (Obj_IsIdFree(*(int *)(*(int *)(*(int *)(param_1 + 0x128) + 0x28) + 0xc)) != 0) {
        TailForwardTrackEntry_2(param_2 & 0xffff, *(int *)(*(int *)(param_1 + 0x128) + 0x28), 1, 0);
        return 1;
    }
    return 0;
}
