extern void Ov054_RecenterSubObjectAndCopyVec();
struct b1_694 { unsigned char b : 1; };
void Ov054_ForwardPlus10IfFlag694(int param_1, int param_2)
{
    if (!((struct b1_694 *)(param_1 + 0x694))->b)
        return;
    Ov054_RecenterSubObjectAndCopyVec(param_1, param_2 + 0x10);
}
