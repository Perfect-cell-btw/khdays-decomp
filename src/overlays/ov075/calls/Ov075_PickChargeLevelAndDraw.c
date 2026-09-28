extern void Ov075_ApplyChargeLevelOnce(int self, int lvl);
extern void Scene_DrawNode(int a);
extern int Sequence_UpdateTracks(int a, int b);

typedef struct { unsigned char b0 : 1; } Flags;

void Ov075_PickChargeLevelAndDraw(int self) {
    int *blk = (int *)(self + 0x2c80);
    int go = 0;
    int lvl = go - 1;
    switch (*(int *)(self + 0x6bc)) {
    default:
        break;
    case 0x20:
        if (*(int *)(self + 0x7b0) >= 0x18000) {
            lvl = go;
            go = 1;
        }
        break;
    case 0x25: {
        int t = *(int *)(self + 0x7b0);
        if (t >= 0xc000) {
            lvl = go;
            go = 1;
        }
        if (t >= 0x12000) lvl = 1;
        if (t >= 0x18000) lvl = 2;
        if (t >= 0x24000) lvl = 3;
        break;
    }
    }
    if (go != 0) {
        Ov075_ApplyChargeLevelOnce(self, lvl);
    }
    if (blk[0] != 1) return;
    if (((Flags *)(self + 0x694))->b0) {
        Scene_DrawNode((int)blk + 0xc);
    }
    if (Sequence_UpdateTracks((int)blk + 0xc, *(short *)(self + 0x2a00 + 0xba)) != 0) {
        blk[0] = 0;
    }
}
