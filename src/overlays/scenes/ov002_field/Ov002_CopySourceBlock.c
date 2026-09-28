/* Copies the current 8-byte source block into the buffer; returns the buffer, or 0 when there is no
 * source. */

extern void MI_CpuCopy8();
extern int data_ov002_0207f610;

int Ov002_CopySourceBlock(int arg0) {
    int p = *(int *)&data_ov002_0207f610;
    if (p == 0) {
        return 0;
    }
    MI_CpuCopy8(p, arg0, 8);
    return arg0;
}
