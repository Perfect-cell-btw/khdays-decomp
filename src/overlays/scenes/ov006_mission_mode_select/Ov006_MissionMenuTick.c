/* Ov006_MissionMenuTick -- Mission Mode: main-menu tick, returns the next scene state (0 = stay).
 * While the menu is still opening (Ov006_Link_GetField49C) it only waits for the open animation
 * to finish and then advances to Ov006_MissionInitVideoScene. Once open, a committed selection
 * (Ov006_MissionCommitEntry) clears the 8-byte selection block at OBJ+0x38, stops the menu tweens
 * and the cursor, and advances to Ov006_UpdateMissionMenuOptionScreen. */
extern int  Ov006_Link_GetField49C(void);
extern int  Ov006_Link_GetField4F0(void);
extern int  Ov006_MissionCommitEntry(void);
extern void MI_CpuFill8(void *dst, int data, unsigned int size);
extern void Ov006_RequestMenuState(int a, int b, int c);
extern void Ov006_MissionScene_SetByte95AC(int a);
extern void Ov006_MissionInitVideoScene(void);
extern void Ov006_UpdateMissionMenuOptionScreen(void);
extern int  data_ov006_02056660;

void *Ov006_MissionMenuTick(void) {
    void *next = 0;
    if (Ov006_Link_GetField49C() == 0) {
        if (Ov006_Link_GetField4F0() != 0) {
            return (void *)Ov006_MissionInitVideoScene;
        }
        return next;
    }
    if (Ov006_MissionCommitEntry() != 0) {
        void *sel = *(char **)&data_ov006_02056660 + 0x38;
        /* `clear` is next's still-zero value: the ROM keeps both in the same callee-saved
         * register and reloads it with Ov006_UpdateMissionMenuOptionScreen before the fill call, so the
         * capture-then-reassign order below is what reproduces its schedule. */
        int clear = (int)next;
        next = (void *)Ov006_UpdateMissionMenuOptionScreen;
        MI_CpuFill8(sel, clear, 8);
        Ov006_RequestMenuState(0, 0, 0);
        Ov006_MissionScene_SetByte95AC(0);
    }
    return next;
}
