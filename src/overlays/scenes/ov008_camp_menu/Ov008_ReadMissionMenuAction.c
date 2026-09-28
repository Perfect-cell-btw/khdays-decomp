/* Ov008_ReadMissionMenuAction -- decide the title's input action from the pad + gate state, ov006.
 * Reduces the latched pad bits (data_0204c190) to a single selector: confirm (bit0) wins over
 * cancel (bit1). With confirm selected and the title fully active (base+0x20 != 0) and the
 * confirm repeat past 1 (Ov008_CountLocalPlayers), requests action 1 (Start). With cancel selected,
 * requests action 3. Finally, when the title is not yet active (base+0x20 == 0) and the attract
 * timer expired (Ov008_Link_Poll == 1), forces action 1. Returns the action code (0/1/3). */
extern int Ov008_CountLocalPlayers(void);
extern int Ov008_Link_Poll(void);
extern unsigned short data_0204c190;
extern int data_ov008_02090fa0;

int Ov008_ReadMissionMenuAction(void) {
    unsigned short flags = data_0204c190;
    int result = 0;
    int sel = 0;
    if (flags & 2) {
        sel = 2;
    }
    if (flags & 1) {
        sel = 1;
    }
    if ((sel & 1) && *(int *)(data_ov008_02090fa0 + 0x20) != 0 &&
        (unsigned int)Ov008_CountLocalPlayers() > 1) {
        result = 1;
    }
    if (sel & 2) {
        result = 3;
    }
    if (*(int *)(data_ov008_02090fa0 + 0x20) == 0 && Ov008_Link_Poll() == 1) {
        result = 1;
    }
    return result;
}
