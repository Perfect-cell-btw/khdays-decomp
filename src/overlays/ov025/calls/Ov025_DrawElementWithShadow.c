/* Draw a text/box element, optionally preceded by a drop-shadow pass offset by (+1,+1,-1). Both
 * passes use flags 0x821. */
extern void Text_DrawDirectional_2(int p1, int p2, int p3, int p4, int flags, int p6);

void Ov025_DrawElementWithShadow(int p1, int p2, int p3, int p4, int bShadow, int p6) {
    if (bShadow != 0) {
        Text_DrawDirectional_2(p1, p2 + 1, p3 + 1, p4 - 1, 0x821, p6);
    }
    Text_DrawDirectional_2(p1, p2, p3, p4, 0x821, p6);
}
