/* The first time it runs outside shutdown, sets game flag 0x2086, notifies the party when the root
 * counter at +0x8ca4 is positive, and updates the rate panel in mode 4 unless flag 0x20e8 is set;
 * returns whether flag 0x2086 is set. */

extern int GameState_IsFlagSet(int flag);
extern int GameState_SetFlag(int flag);
extern int Ov002_RunShutdownHook(void);
extern void func_ov022_02083fa4(int a);
extern void Ov002_UpdateRatePanel(void);

extern int data_ov002_0207fa00;
extern unsigned char data_0204c240;

int Ov002_TriggerOnceOnFlag(void) {
    char *ctx = *(char **)&data_ov002_0207fa00;

    if (GameState_IsFlagSet(0x2086) == 0 && Ov002_RunShutdownHook() == 0) {
        GameState_SetFlag(0x2086);
        if (*(short *)(ctx + 0x8ca4) > 0) {
            func_ov022_02083fa4(1);
        }
        if ((data_0204c240 & 4) != 0 && GameState_IsFlagSet(0x20e8) == 0) {
            Ov002_UpdateRatePanel();
        }
    }
    return GameState_IsFlagSet(0x2086);
}
