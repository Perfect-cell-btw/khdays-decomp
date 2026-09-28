extern int data_ov002_0207fa14;
extern int GetEntryField20ByIndex(int arg0);
extern int Ov022_RequestGuardBreak(int arg0);

int Ov002_ResolveActorIfSlotBound(int arg0) {
    if (*(signed char *)(*(int *)&data_ov002_0207fa14 + 0x96) >= 0) {
        return 0;
    }
    return Ov022_RequestGuardBreak(GetEntryField20ByIndex(arg0));
}
