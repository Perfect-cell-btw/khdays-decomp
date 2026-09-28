/* While the character is shown, draws its effect node at its offset position. */

extern void Ov055_DrawNodeWithOffsetPos();
struct b1_694 { unsigned char b : 1; };
void Ov055_ForwardPlus14IfFlag694(int param_1, int param_2)
{
    if (!((struct b1_694 *)(param_1 + 0x694))->b)
        return;
    Ov055_DrawNodeWithOffsetPos(param_1, param_2 + 0x14);
}
