/* If +0x6c is set, hand to 020ce714. Else, unless busy, if +0x54 is under 3 hand to 020ce778;
 * otherwise clear both linked nodes' +0x398, latch +0x74+2 and dispatch. */
extern int SetIndexedSlot(int, int, void *);
extern int Ov256_AiArmClawsAndStep(int);
extern int Ov256_Reaction_AdvanceStepAndDispatch(int);
void Ov256_AiClawStepLoop(int param_1) {
    int owner = *(int *)(param_1 + 4);
    if (*(int *)(owner + 0x6c) != 0) {
        SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov256_AiArmClawsAndStep);
        return;
    }
    if (*(unsigned char *)(*(int *)(owner + 4) + 0xad) != 0) return;
    if (*(int *)(owner + 0x54) < 3) {
        SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov256_Reaction_AdvanceStepAndDispatch);
        return;
    }
    *(int *)(*(int *)(*(int *)owner + 0x434) + 0x398) = 0;
    *(int *)(*(int *)(*(int *)owner + 0x438) + 0x398) = 0;
    *(unsigned char *)(*(int *)owner + 0x1c7) = *(int *)(owner + 0x74) + 2;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), 0);
}
