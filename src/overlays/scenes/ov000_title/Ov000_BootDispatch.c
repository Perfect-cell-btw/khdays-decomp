/* Ov000_BootDispatch -- ov000 boot dispatcher. Ticks the scene (PartyState_Reset), then runs the
 * boot path selected by heap+0x4c31: 0 = cold boot (Ov000_BootRunSelector), 1 = resume
 * (Ov000_RequestTitleTransition); any other value falls through with the default -2. Always finishes with
 * Ov000_LatchTick. */
extern int  NNSi_FndGetCurrentRootHeap(void);
extern void PartyState_Reset(int heap);
extern int  Ov000_BootRunSelector(void);
extern int  Ov000_RequestTitleTransition(void);
extern void Ov000_LatchTick(void);

int Ov000_BootDispatch(void) {
    int result = -2;
    int heap = NNSi_FndGetCurrentRootHeap();
    PartyState_Reset(heap);
    switch (*(char *)(heap + 0x4c31)) {
    case 0:
        result = Ov000_BootRunSelector();
        break;
    case 1:
        result = Ov000_RequestTitleTransition();
        break;
    }
    Ov000_LatchTick();
    return result;
}
