/* Ov006_CanConfirmMissionMenu -- test whether the Mission Mode may accept a confirm, ov006.
 * True only when the Mission Mode is idle (base+0x28 == 0) and the confirm-ready check
 * (Ov006_ShouldEnterConfirmState) passes. */
extern int Ov006_ShouldEnterConfirmState(void);
extern int data_ov006_02056660;

int Ov006_CanConfirmMissionMenu(void) {
    if (*(int *)(data_ov006_02056660 + 0x28) == 0 && Ov006_ShouldEnterConfirmState() != 0) {
        return 1;
    }
    return 0;
}
