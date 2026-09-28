extern int TaskList_FinishByTag();
extern int Ov107_AiState_PostTickBase();

int Ov222_ReleaseHeldSoundsAndTick(int r0)
{
    signed char c = *(signed char *)(r0 + 0x1c6);
    if (!((c == 9 || c == 0x48) && (*(unsigned char *)(r0 + 0x1c4) & 0xa) == 0)) {
        int a = *(int *)(r0 + 0x440);
        if (a) {
            TaskList_FinishByTag(*(int *)(r0 + 0x3c), a);
            *(int *)(r0 + 0x440) = 0;
        }
        a = *(int *)(r0 + 0x448);
        if (a) {
            TaskList_FinishByTag(*(int *)(r0 + 0x3c), a);
            *(int *)(r0 + 0x448) = 0;
        }
    }
    return Ov107_AiState_PostTickBase(r0);
}
