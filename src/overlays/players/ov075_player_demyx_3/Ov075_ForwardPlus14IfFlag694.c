extern void Ov075_DrawNodeWithOffsetPos();
struct b1_694 { unsigned char b : 1; };
void Ov075_ForwardPlus14IfFlag694(int param_1, int param_2)
{
    if (!((struct b1_694 *)(param_1 + 0x694))->b)
        return;
    Ov075_DrawNodeWithOffsetPos(param_1, param_2 + 0x14);
}
