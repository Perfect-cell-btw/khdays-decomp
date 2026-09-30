/* Post-tick: unless the current action holds them (9 or 0x48 with bits 0xa of +0x1c4 clear),
 * finishes the two held sound tasks (+0x440, +0x448); then runs the base post-tick. */

extern int TaskList_FinishByTag();
extern int Ov107_AiState_PostTickBase();

int Ov221_ReleaseHeldSoundsAndTick(int r0)
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
