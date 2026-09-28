extern int GameState_IsFlagSet(int id);
extern void GameState_SetFlag(int id);
extern int func_ov022_02086ef4(void);
extern int func_ov022_02086f24(void);
extern int Ov002_RunShutdownHook(void);
extern void func_ov022_02083fa4(int a);
extern char *data_ov002_0207fa00;

/* Keeps the field music in step with the mission state: switches to the alternate track while the
 * trigger is armed, otherwise restores the normal one and re-arms the ambience. Returns whether
 * game-state flag 0x20e2 is set once the update is done. */
int Ov002_UpdateFieldMusic(void) {
    char *self = data_ov002_0207fa00 + 0x8c94;
    if (GameState_IsFlagSet(0x2086) != 0 && func_ov022_02086ef4() != 0 &&
        func_ov022_02086f24() == 0) {
        GameState_SetFlag(0x20e2);
    } else if (GameState_IsFlagSet(0x20e2) == 0 && Ov002_RunShutdownHook() == 0) {
        GameState_SetFlag(0x20e2);
        if (*(int *)(self + 0xc) > 0) {
            func_ov022_02083fa4(0);
        }
    }
    return GameState_IsFlagSet(0x20e2);
}
