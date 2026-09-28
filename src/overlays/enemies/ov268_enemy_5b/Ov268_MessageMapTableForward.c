/*
 * Ov268_MessageMapTableForward -- x3. Message handler: map the message kind through a 15-entry table and
 * forward. A local copy of the const table (data_020d4798) is indexed by kind; the result feeds
 * 020c9440(self, table[kind]), whose handle goes to 020d0628(*(self+0x384), handle, arg3, self+0x388).
 * Finish with a reset (0203c7ac).
 */
struct t15 { int w[15]; };
extern int  Ov107_PackTextureHandle(int self, int x);
extern void Ov268_BindClip(int a, int b, int c, int d);
extern void RefreshObjectCallbacks(int a, int b);
extern struct t15 data_ov268_020d47c4;

void Ov268_MessageMapTableForward(int self, int kind, int arg3) {
    struct t15 table = data_ov268_020d47c4;

    Ov268_BindClip(*(int *)(self + 0x384), Ov107_PackTextureHandle(self, table.w[kind]), arg3,
                        self + 0x388);
    RefreshObjectCallbacks(*(int *)(self + 0x384), 0);
}
