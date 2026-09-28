extern int NNSi_FndGetCurrentRootHeap(void);
extern void func_ov022_02086d0c(int a);
extern int GameState_IsFlagSet(int id);
extern void PlaySoundChecked(int a, int b);
extern void func_020235bc(int id);
extern void func_ov022_020869f4(void);
extern void Ov022_StepSelectionSchedule(void);

int Ov022_AdvanceFadeStateThenNextStep(void) {
    int heap = NNSi_FndGetCurrentRootHeap();
    int r = 0;
    if (*(signed char *)(heap + 0xc0) == 1) {
        *(signed char *)(heap + 0xc0) = 2;
        *(signed char *)(heap + 0xc2) = 0;
        *(signed char *)(heap + 0xc1) = 0;
        r = (int)func_ov022_020869f4;
    }
    if (*(signed char *)(heap + 0xc0) == 4) {
        *(signed char *)(heap + 0xc0) = 5;
        func_ov022_02086d0c(1);
        if (GameState_IsFlagSet(0x20ed) == 0) PlaySoundChecked(0, 0x28);
        func_020235bc(0x20ed);
        r = (int)Ov022_StepSelectionSchedule;
    }
    return r;
}
