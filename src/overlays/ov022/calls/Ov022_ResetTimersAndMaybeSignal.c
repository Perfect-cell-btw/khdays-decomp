extern int Session_GetLocalPlayerIndex(void);
extern void Ov002_World_AddStat(int a, int b);
extern void Ov022_ActorSetState(int obj, int a);
extern int data_0204c240;

void Ov022_ResetTimersAndMaybeSignal(int arg0, int arg1) {
    *(int *)(arg0 + 0x698) = 0;
    *(int *)(arg0 + 0x69c) = 0x630;
    *(int *)(arg0 + 0x6a0) = 0;
    if (Session_GetLocalPlayerIndex() == 0) {
        *(unsigned long long *)(arg0 + 0x464) |= 0x20LL;
    }
    if (arg1 == 0 && (*(unsigned char *)&data_0204c240 & 4) == 0) {
        if ((*(unsigned int *)arg0 & 0x10000) == 0 && *(unsigned char *)(arg0 + 9) == 0)
            Ov002_World_AddStat(1, 3);
    }
    Ov022_ActorSetState(arg0, 1);
}
