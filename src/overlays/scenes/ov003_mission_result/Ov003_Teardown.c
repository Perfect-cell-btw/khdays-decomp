/* Tears the mission result scene down: unregisters its VBlank callback, stops touch sampling, and
 * frees its buffers, resources, models and camera. */

extern int NNSi_FndGetCurrentRootHeap(void);
extern void VBlank_UnregisterCallback(int a, void *b);
extern void TP_RequestAutoSamplingStopAsync(void);
extern void TP_WaitBusy(int a);
extern void TP_CheckError(int a);
extern void FSi_BindCardTransfer(int a);
extern void NNSi_FndFreeFromDefaultHeap(int a);
extern void FreeAllResourceTables(int p);
extern void ReleaseField74AndCleanup(int p);
extern void CamAnim_Release(void *p);
extern void Gfx_SetupSubEngine(void *p);
extern void ZeroHalfThenFree(void *p);
extern int data_ov003_0204f978;

void Ov003_Teardown(void) {
    unsigned short *root;
    int base;
    int i108;
    int iVar3;
    int puVar4;
    int puVar5;
    int puVar6;
    int puVar7;
    int puVar8;
    int puVar9;

    root = (unsigned short *)NNSi_FndGetCurrentRootHeap();
    VBlank_UnregisterCallback(1, &data_ov003_0204f978);
    TP_RequestAutoSamplingStopAsync();
    TP_WaitBusy(4);
    TP_CheckError(4);
    FSi_BindCardTransfer(0);
    if (*(int *)(root + 0xede) != 0) {
        NNSi_FndFreeFromDefaultHeap(*(int *)(root + 0xede));
    }
    NNSi_FndFreeFromDefaultHeap(*(int *)(root + 0xedc));
    iVar3 = *root - 1;
    if (iVar3 >= 0) {
        base = (int)root;
        puVar4 = base + 0x16c0 + iVar3 * 0x24;
        i108 = iVar3 * 0x108;
        puVar5 = base + 0x12a0 + i108;
        puVar6 = base + 0xe70 + i108;
        puVar7 = base + 0xa50 + i108;
        puVar8 = base + 0x210 + i108;
        puVar9 = base + 0x630 + i108;
        do {
            FreeAllResourceTables(puVar4);
            ReleaseField74AndCleanup(puVar5);
            if (((int *)root)[iVar3 + 0x4a4] != 0) {
                ReleaseField74AndCleanup(puVar6);
            }
            ReleaseField74AndCleanup(puVar7);
            ReleaseField74AndCleanup(puVar8);
            ReleaseField74AndCleanup(puVar9);
            puVar4 = puVar4 - 0x24;
            puVar5 = puVar5 - 0x108;
            puVar6 = puVar6 - 0x108;
            puVar7 = puVar7 - 0x108;
            puVar8 = puVar8 - 0x108;
            puVar9 = puVar9 - 0x108;
            iVar3 = iVar3 - 1;
        } while (iVar3 >= 0);
    }
    ReleaseField74AndCleanup((int)(root + 0x84));
    CamAnim_Release(root + 0x58);
    CamAnim_Release(root + 0x2c);
    Gfx_SetupSubEngine(root + 0x22);
    ZeroHalfThenFree(*(void **)(root + 0x20));
}
