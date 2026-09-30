/*
 * Ov274_MessageArmEmitterTable -- x4. Message handler: on kinds 6 and 0xa, (re-)arm the emitter, then map the
 * message kind through a 17-entry table and forward. A local copy of the const table (data_020d0564)
 * is indexed by kind. Kinds 6 and 0xa re-arm via 020c09a0 (mode 0x17, anchor self+0x9c+0x30), differing
 * only in the 5th argument (0 for 6, 1 for 0xa); the handle goes to *(self+0x3e0)+0x14. Then
 * 020cc85c(*(self+0x384), 020c9440(self, table[kind]), arg3, self+0x388), and a reset (0203c7ac).
 */
struct t17 { int w[17]; };
extern int  Ov107_CreateNodeBodyTask(int a, int b, int mode, int anchor, int e, int f);
extern int  Ov107_PackTextureHandle(int self, int x);
extern void Ov274_BindClip(int a, int b, int c, int d);
extern void RefreshObjectCallbacks(int a, int b);
extern struct t17 data_ov274_020d41a8;

void Ov274_MessageArmEmitterTable(int self, int kind, int arg3) {
    struct t17 table = data_ov274_020d41a8;

    if (kind == 6) {
        *(int *)(*(int *)(self + 0x3e0) + 0x14) = Ov107_CreateNodeBodyTask(
            *(int *)(self + 0x3c), *(int *)(*(int *)(self + 0x3e0) + 0x10), 0x17,
            *(int *)(self + 0x9c) + 0x30, 0, 0);
    } else if (kind == 0xa) {
        *(int *)(*(int *)(self + 0x3e0) + 0x14) = Ov107_CreateNodeBodyTask(
            *(int *)(self + 0x3c), *(int *)(*(int *)(self + 0x3e0) + 0x10), 0x17,
            *(int *)(self + 0x9c) + 0x30, 1, 0);
    }
    Ov274_BindClip(*(int *)(self + 0x384), Ov107_PackTextureHandle(self, table.w[kind]), arg3,
                        self + 0x388);
    RefreshObjectCallbacks(*(int *)(self + 0x384), 0);
}
