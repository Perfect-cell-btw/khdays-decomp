/* Refreshes the current phase and, in state 3, updates the scene's widget. */

extern void Ov011_RefreshCurrentPhase();
extern int data_ov011_0205e960;
extern void func_0203256c();

void Ov011_RunSetupThenInvokeIfState3(void) {
    int r1;
    Ov011_RefreshCurrentPhase();
    r1 = *(int *)((char *)&data_ov011_0205e960 + 4);
    if (*(int *)(r1 + 4) != 3) return;
    func_0203256c(r1 + 0x28508);
}
