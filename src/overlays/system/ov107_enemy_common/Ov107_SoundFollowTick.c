/* Poll 02033ea0: on empty hand off to 0203c640; otherwise refresh the bar, and if it is active
 * but not flagged bail, then depending on +8 either hand off again or step 02033e48 and dispatch. */
extern int SoundSeqHandle_IsActive(int);
extern int Task_MarkFinished(int);
extern int Handle_WritePayloadIfLive(int, int);
extern int SoundSeqHandle_Stop(int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov107_SoundRestartTick(int);
struct sb { int b0 : 1; };
void Ov107_SoundFollowTick(int param_1) {
    int owner = *(int *)(param_1 + 4);
    if (SoundSeqHandle_IsActive(*(int *)(owner + 0x10)) == 0) {
        Task_MarkFinished(param_1);
        return;
    }
    Handle_WritePayloadIfLive(*(int *)(owner + 0x10), *(int *)(owner + 0xc) + 0x10);
    int obj = *(int *)owner;
    if (((struct sb *)(obj + 0x40))->b0 != 0) {
        if ((*(unsigned char *)(obj + 0x1c4) & 2) == 0) return;
    }
    if (*(int *)(owner + 8) == 0) {
        Task_MarkFinished(param_1);
        return;
    }
    SoundSeqHandle_Stop(*(int *)(owner + 0x10));
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov107_SoundRestartTick);
}
