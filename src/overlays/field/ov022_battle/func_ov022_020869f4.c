/* Moves the result fade to state 3 (and its sub-state to 4 when needed); returns the fade step. */

extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov022_AdvanceFadeStateThenNextStep(void);

int func_ov022_020869f4(void) {
    int h = NNSi_FndGetCurrentRootHeap();
    if (*(char *)(h + 0xc3) == 0) {
        *(unsigned char *)(h + 0xc0) = 3;
        return (int)Ov022_AdvanceFadeStateThenNextStep;
    }
    *(unsigned char *)(h + 0xc2) = 4;
    *(unsigned char *)(h + 0xc0) = 3;
    return (int)Ov022_AdvanceFadeStateThenNextStep;
}
