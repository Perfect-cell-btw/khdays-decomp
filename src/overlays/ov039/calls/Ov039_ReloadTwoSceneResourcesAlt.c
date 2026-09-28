extern void func_ov022_0209fb60(int a, int b, int c);
extern void Ov022_SetSlotClaim(int a, int b, int c);
extern void Ov002_BuildPanelIdSummary(int a, int b, int c);
extern void Ov002_LoadAnimTables(int a, int b, int c, int d, int e);
extern int data_ov039_020b5600;

void Ov039_ReloadTwoSceneResourcesAlt(int self) {
    int base = *(int *)&data_ov039_020b5600;
    func_ov022_0209fb60(base, 0, 3);
    Ov022_SetSlotClaim(base, 0, 1);
    if (*(signed char *)(base + 0xda9) != 0) {
        *(unsigned char *)(base + 0xda8) |= 1;
    }
    Ov002_BuildPanelIdSummary(base + 0xda8, base + 0x2c2c, self + 0x910);
    Ov002_LoadAnimTables(self + 0xda8, base + 0x2c2c, *(int *)(self + 0x2bd0),
                        *(unsigned char *)(self + 9), 0x78);
    func_ov022_0209fb60(base, 1, 4);
    Ov022_SetSlotClaim(base, 1, 1);
    if (*(signed char *)(base + 0xf0d) != 0) {
        *(unsigned char *)(base + 0xf0c) |= 1;
    }
    Ov002_BuildPanelIdSummary(base + 0xf0c, base + 0x2c80, self + 0x910);
    Ov002_LoadAnimTables(self + 0xf0c, base + 0x2c80, *(int *)(self + 0x2bd0),
                        *(unsigned char *)(self + 9), 0xbe);
}
