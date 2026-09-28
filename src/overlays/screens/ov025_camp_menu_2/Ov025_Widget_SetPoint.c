/* Stores a widget's point (+0x2c). */

extern void MI_CpuCopy8();

void Ov025_Widget_SetPoint(int arg0, int arg1, int arg2) {
    MI_CpuCopy8(arg2, arg1 + 0x2c, 8);
}
