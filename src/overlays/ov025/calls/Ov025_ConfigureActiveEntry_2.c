extern int Ov025_FindActiveEntryByTag();
extern void Ov025_ReapplyEditsAndCommit();
extern void Ov025_SetTagTrackerNodeArmed();

void Ov025_ConfigureActiveEntry_2(int arg0, unsigned int arg1, unsigned short arg2, unsigned short arg3) {
    int e = Ov025_FindActiveEntryByTag(arg0, arg1 & 0xffff);
    Ov025_ReapplyEditsAndCommit(arg0, e, arg2, arg3);
    Ov025_SetTagTrackerNodeArmed(arg0, e, 1);
}
