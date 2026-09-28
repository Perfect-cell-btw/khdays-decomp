extern void func_ov022_0209fb60(int a, int b, int c);
extern void Ov002_BuildPanelIdSummary(int a, int b, int c);
extern void Ov002_LoadAnimTables(int a, int b, int c, int d, int e);
extern int data_ov104_020bc2a0;

void Ov104_ReloadTwoSceneResources(int self) {
    int base = *(int *)&data_ov104_020bc2a0;
    func_ov022_0209fb60(base, 0, 1);
    if (*(signed char *)(base + 0xda9) != 0) {
        *(unsigned char *)(base + 0xda8) |= 1;
    }
    Ov002_BuildPanelIdSummary(base + 0xda8, base + 0x2c54, self + 0x910);
    Ov002_LoadAnimTables(self + 0xda8, base + 0x2c54, *(int *)(self + 0x2bd0),
                        *(unsigned char *)(self + 9), 0x78);
    func_ov022_0209fb60(base, 1, 2);
    if (*(signed char *)(base + 0xf0d) != 0) {
        *(unsigned char *)(base + 0xf0c) |= 1;
    }
    Ov002_BuildPanelIdSummary(base + 0xf0c, base + 0x2ca8, self + 0x910);
    Ov002_LoadAnimTables(self + 0xf0c, base + 0x2ca8, *(int *)(self + 0x2bd0),
                        *(unsigned char *)(self + 9), 0xbe);
}
