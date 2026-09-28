/* Flag both linked nodes (+0x434/+0x438 -> +0x398=1); if 020ccd54 accepts, snap +0x40 to +0x44
 * and clear +0x6c; always clear +0x54 and dispatch. */
extern int Ov256_PickTarget(int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov256_Reaction_AdvanceStepAndDispatch(int);
void Ov256_AiArmClawsAndStep(int param_1) {
    int owner = *(int *)(param_1 + 4);
    *(int *)(*(int *)(*(int *)owner + 0x434) + 0x398) = 1;
    *(int *)(*(int *)(*(int *)owner + 0x438) + 0x398) = 1;
    if (Ov256_PickTarget(param_1) != 0) {
        *(int *)(owner + 0x40) = *(int *)(owner + 0x44);
        *(int *)(owner + 0x6c) = 0;
    }
    *(int *)(owner + 0x54) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov256_Reaction_AdvanceStepAndDispatch);
}
