/* Reloads the character's message container and, unless a story flag blocks it, re-claims its
 * battle slot and rebuilds its panel id summary and animation tables; frees the old container. */

extern int GameState_IsFlagSet(int a);
extern int Msg_OpenContainerAndReadHeader(void *a, int b);
extern void func_ov022_0209fb60(int a, int b, int c);
extern void Ov002_BuildPanelIdSummary(int a, int b, int c);
extern void Ov002_LoadAnimTables(int a, int b, int c, int d, int e);
extern void ZeroHalfThenFree(int a);
extern int data_ov099_020bcbc0;
extern unsigned char data_0204c240;
extern int data_ov099_020bcb1c;

void Ov099_ReloadSceneResources(int self) {
    int base = *(int *)&data_ov099_020bcbc0;
    int obj = *(int *)(self + 0x2bd0);
    int ok = 1;
    if ((data_0204c240 & 4) == 0 && GameState_IsFlagSet(0x208c) != 0) {
        ok = 0;
    }
    *(int *)(self + 0x2bd0) = Msg_OpenContainerAndReadHeader(&data_ov099_020bcb1c, 6);
    if (ok != 0) {
        func_ov022_0209fb60(base, 1, 2);
        if (*(signed char *)(base + 0xf0d) != 0) {
            *(unsigned char *)(base + 0xf0c) |= 1;
        }
        Ov002_BuildPanelIdSummary(base + 0xf0c, base + 0x2c54, self + 0x910);
        Ov002_LoadAnimTables(self + 0xf0c, base + 0x2c54, obj,
                            *(unsigned char *)(self + 9), 0x78);
    }
    ZeroHalfThenFree(obj);
}
