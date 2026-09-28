/* Copies the current 8-byte source block into the buffer; returns the buffer, or 0 when there is no
 * source. */

extern void MI_CpuCopy8();
extern int data_ov025_020b5754;

int Ov025_CopySourceBlock(int arg0) {
    int g = data_ov025_020b5754;
    if (g == 0) {
        return 0;
    }
    MI_CpuCopy8(g, arg0, 8);
    return arg0;
}
