/* While the character is shown, draws the effect node when it is in its visible state and the
 * sub-node turned with the character. */

extern void Scene_DrawNode();
extern void Ov037_SetYawAndDrawSubNode();

struct b1 { unsigned char b : 1; };

void Ov037_ForwardArg1IfFlagSet(int this_, int arg1) {
    if (((struct b1 *)(this_ + 0x694))->b == 0) return;
    if (*(int *)arg1 == 2) {
        Scene_DrawNode(arg1 + 4);
    }
    Ov037_SetYawAndDrawSubNode(this_, arg1);
}
