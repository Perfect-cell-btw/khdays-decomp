extern int Ov002_ResolveSelectedPanel(void);
extern int Ov002_World_IsFlagBitSet(int a);
extern int Ov002_SetPanelField003c(int a);
extern int Ov002_SetSeatFlag(int a, int b);
extern int Ov002_GetPanelField018c(void);

/* Poll the ov002 menu flow: report busy (1) while a transition is pending; if a
 * pending action is queued, kick it and clear it; report busy again if a new
 * request arrived, else idle (0). */
int Ov019_PollMenuFlow(void) {
    if (Ov002_ResolveSelectedPanel() != 0) {
        return 1;
    }
    if (Ov002_World_IsFlagBitSet(0) != 0) {
        Ov002_SetPanelField003c(1);
        Ov002_SetSeatFlag(0, 0);
    }
    if (Ov002_GetPanelField018c() != 0) {
        return 1;
    }
    return 0;
}
