/* Re-arm three tag-tracker nodes in one go: tag 9 off, tags 0xb and 8 on. */
extern int Ov002_Ctx_FindActiveEntryByTag(int tag);
extern void Ov002_Ctx_SetTagTrackerNodeArmed_5(int node, int armed);

void Ov002_ArmHudTagGroup(void) {
    Ov002_Ctx_SetTagTrackerNodeArmed_5(Ov002_Ctx_FindActiveEntryByTag(9), 0);
    Ov002_Ctx_SetTagTrackerNodeArmed_5(Ov002_Ctx_FindActiveEntryByTag(0xb), 1);
    Ov002_Ctx_SetTagTrackerNodeArmed_5(Ov002_Ctx_FindActiveEntryByTag(8), 1);
}
