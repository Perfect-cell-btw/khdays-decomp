/* Creates a child task entry that binds, for each type id in the list (up to 16, 0 ends it), the
 * first subitem of the model with that id. */

extern int CreateRegistryEntry(int obj, int a, int b, void *cb1, void *cb2, int **out);
extern int *List_First(int p);
extern int *List_Next(int p);
extern void Ov150_stateAttachSubitemInit(void);
extern void Ov150_ChildTaskTeardown(void);
int Ov150_bindSubitemsByTypeId(int param_1, int param_2) {
    int *local_28;
    int iVar1 = CreateRegistryEntry(*(int *)(param_1 + 0x3c), 0x64, 0x48,
                              Ov150_stateAttachSubitemInit, Ov150_ChildTaskTeardown, &local_28);
    int iVar5 = 0;
    *local_28 = param_1;
    int iVar4 = *(int *)(*local_28 + 4);
    do {
        int *piVar2;
        int iVar3;
        if (((unsigned short *)param_2)[iVar5] == 0) break;
        piVar2 = List_First(iVar4 + 0x80);
        iVar3 = (piVar2 == 0) ? 0 : *piVar2;
        if (iVar3 != 0) {
            do {
                unsigned short pv = ((unsigned short *)param_2)[iVar5];
                if (pv == *(unsigned short *)(iVar3 + 2)) {
                    local_28[iVar5 + 2] = iVar3;
                    break;
                }
                piVar2 = List_Next(iVar4 + 0x80);
                iVar3 = (piVar2 == 0) ? 0 : *piVar2;
            } while (iVar3 != 0);
        }
        iVar5++;
    } while (iVar5 < 0x10);
    return iVar1;
}
