/* Ov006_ReadMissionMenuAction -- decide the Mission Mode's input action from the pad + gate state, ov006.
 * Reduces the latched pad bits (gPadPressed) to a single selector: confirm (bit0) wins over
 * cancel (bit1). With confirm selected and the Mission Mode fully active (base+0x20 != 0) and the
 * confirm repeat past 1 (Ov006_CountLocalPlayers), requests action 1 (Start). With cancel selected,
 * requests action 3. Finally, when the Mission Mode is not yet active (base+0x20 == 0) and the attract
 * timer expired (Ov006_Link_Poll == 1), forces action 1. Returns the action code (0/1/3). */
extern int Ov006_CountLocalPlayers(void);
extern int Ov006_Link_Poll(void);
extern unsigned short gPadPressed;
extern int data_ov006_02056660;

int Ov006_ReadMissionMenuAction(void) {
    unsigned short flags = gPadPressed;
    int result = 0;
    int sel = 0;
    if (flags & 2) {
        sel = 2;
    }
    if (flags & 1) {
        sel = 1;
    }
    if ((sel & 1) && *(int *)(data_ov006_02056660 + 0x20) != 0 &&
        (unsigned int)Ov006_CountLocalPlayers() > 1) {
        result = 1;
    }
    if (sel & 2) {
        result = 3;
    }
    if (*(int *)(data_ov006_02056660 + 0x20) == 0 && Ov006_Link_Poll() == 1) {
        result = 1;
    }
    return result;
}
