extern int NNSi_FndGetCurrentRootHeap(void);
extern int func_02023c40(void);
extern void Ov022_SetGlobalByte(int on);
extern void func_020362ec(int a);
extern int Session_GetLocalPlayerIndex(void);
extern void Ov022_RefreshSlotRows(int a);
extern void Ov022_Party_SyncAndUpdate(int a);
extern void Ov022_StepPrimaryNodeTarget(int a);
extern void Ov022_Party_ShowNearbyNames(void);
extern void Ov022_SceneTickHookNoOp(int a);
extern void func_ov022_02087f30(void);
extern int data_0204be04;

int Ov022_TickSceneDispatch(void) {
    int heap = NNSi_FndGetCurrentRootHeap();
    unsigned int mode;
    Ov022_SetGlobalByte(func_02023c40() == 1);
    func_020362ec(heap + 0x4c);
    mode = *(unsigned char *)&data_0204be04;
    if (mode == 0) {
        int t = Session_GetLocalPlayerIndex();
        if (t == 0) Ov022_RefreshSlotRows(t);
        else Ov022_Party_SyncAndUpdate(t);
    } else {
        Ov022_StepPrimaryNodeTarget(mode);
    }
    Ov022_Party_ShowNearbyNames();
    Ov022_SceneTickHookNoOp(heap + 0x68);
    func_ov022_02087f30();
    return 0;
}
