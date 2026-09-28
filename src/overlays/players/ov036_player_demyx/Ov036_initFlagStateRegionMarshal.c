/* Sets up this overlay's shared battle object (slot claims in the battle module, ready bit when
 * enabled), then builds its panel id summary and loads its animation tables. */

extern void func_ov022_0209fb60(int a, int b, int c);
extern void Ov022_SetSlotClaim(int a, int b, int c);
extern void Ov002_BuildPanelIdSummary(int a, int b, int c);
extern void Ov002_LoadAnimTables(int a, int b, int c, int d, int e);
extern int *data_ov036_020b4f40;
void Ov036_initFlagStateRegionMarshal(int param) {
    int obj = (int)data_ov036_020b4f40;
    func_ov022_0209fb60(obj, 0, 3);
    Ov022_SetSlotClaim(obj, 0, 1);
    if (*(signed char *)(obj + 0xda9) != 0)
        *(unsigned char *)(obj + 0xda8) |= 1;
    Ov002_BuildPanelIdSummary(obj + 0xda8, obj + 0x2c2c, param + 0x910);
    Ov002_LoadAnimTables(param + 0xda8, obj + 0x2c2c, *(int *)(param + 0x2bd0),
                        *(unsigned char *)(param + 9), 0x78);
}
