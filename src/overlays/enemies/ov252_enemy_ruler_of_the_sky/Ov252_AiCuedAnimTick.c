/* Reset via 020cdfe8, accumulate the frame delta into +0x64 and +0x6c; when armed (+0x89==1) and
 * +0x6c passes 0xee0, disarm and fire the 0x148/0x13 effect; then unless busy anim 0x25 and dispatch. */
extern int Ov252_CheckTarget(int, int, int);
extern int Ov107_BuildAndSendUpdate(int, int, int, int);
extern int Ov107_PostTagUpdate(int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov252_BlastTick(int);
void Ov252_AiCuedAnimTick(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov252_CheckTarget(param_1, 0, 1);
    *(int *)(owner + 0x64) += *(int *)(*(int *)param_1 + 0x2c);
    *(int *)(owner + 0x6c) += *(int *)(*(int *)param_1 + 0x2c);
    int b = *(unsigned char *)(owner + 0x89);
    if (b == 1) {
        if (*(int *)(owner + 0x6c) >= 0xee0) {
            *(unsigned char *)(owner + 0x89) = b - 1;
            Ov107_BuildAndSendUpdate(*(int *)owner, 0x148, 0x13, *(int *)(owner + 8));
        }
    }
    if (*(unsigned char *)(*(int *)(owner + 4) + 0xad) != 0) return;
    Ov107_PostTagUpdate(*(int *)owner, 0x25, 0);
    *(unsigned char *)(owner + 0x86) = 0;
    *(unsigned char *)(owner + 0x88) = 1;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov252_BlastTick);
}
