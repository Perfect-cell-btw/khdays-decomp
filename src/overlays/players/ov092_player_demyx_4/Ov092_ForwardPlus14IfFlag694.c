extern void Ov092_DrawNodeWithOffsetPos();
struct b1_694 { unsigned char b : 1; };
void Ov092_ForwardPlus14IfFlag694(int param_1, int param_2)
{
    if (!((struct b1_694 *)(param_1 + 0x694))->b)
        return;
    Ov092_DrawNodeWithOffsetPos(param_1, param_2 + 0x14);
}
