/*
 * Ov210_RebuildSubObjectNotify -- x3 (ov210/...). Rebuild the sub-object, then notify with a 1-bit flag.
 * Store func_020d402c(self, node, c, d) into self[0x194]. If self has a notify callback at +0x14,
 * call cb(self, bit1_signed) where bit1_signed = (*(node+0x40) << 30) >> 31 (0 or -1 from bit 1).
 */
extern int Ov210_CreateSwoopTask(int self, int node, int c, int d);

void Ov210_RebuildSubObjectNotify(int self, int node, int c, int d) {
    void (*cb)(int, int);
    int flag;

    *(int *)(self + 0x194) = Ov210_CreateSwoopTask(self, node, c, d);
    flag = (*(int *)(node + 0x40) << 30) >> 31;
    cb = *(void (**)(int, int))(self + 0x14);
    if (cb != 0) {
        cb(self, flag);
    }
}
