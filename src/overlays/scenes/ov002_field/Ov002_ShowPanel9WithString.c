extern int Ov002_Ctx_FindActiveEntryByTag(int slot);
extern void Ov002_Ctx_SetTagTrackerNodeArmed_5(int handle, int flag);
extern int Ov002_ForwardToSubDc(int id);
extern void Ov002_Ctx_InvokeTagTrackerCallback(int handle);
/* Bring up panel 9 and register string 0x5e1 with the HUD. */
void Ov002_ShowPanel9WithString(void) {
    Ov002_Ctx_SetTagTrackerNodeArmed_5(Ov002_Ctx_FindActiveEntryByTag(9), 0);
    Ov002_Ctx_InvokeTagTrackerCallback(Ov002_ForwardToSubDc(0x5e1));
}
