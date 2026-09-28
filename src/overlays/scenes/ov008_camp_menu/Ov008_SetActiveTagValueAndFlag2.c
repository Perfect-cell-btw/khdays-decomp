/* Ov008_SetActiveTagValueAndFlag2 -- push (param_3,param_4) to the active widget for tag param_2, then mark it
 * dirty. Finds the active entry (Ov008_FindActiveEntryByTag), sets its value (Ov008_ReapplyEditsAndCommit), and
 * flags it (Ov008_SetTagTrackerNodeArmed(...,1)). */
extern int  Ov008_FindActiveEntryByTag(int owner, unsigned int tag);
extern void Ov008_ReapplyEditsAndCommit(int owner, int entry, unsigned short a, unsigned short b);
extern void Ov008_SetTagTrackerNodeArmed(int owner, int entry, int flag);

void Ov008_SetActiveTagValueAndFlag2(int param_1, unsigned int param_2, unsigned short param_3, unsigned short param_4) {
    int entry = Ov008_FindActiveEntryByTag(param_1, param_2 & 0xffff);
    Ov008_ReapplyEditsAndCommit(param_1, entry, param_3, param_4);
    Ov008_SetTagTrackerNodeArmed(param_1, entry, 1);
}
