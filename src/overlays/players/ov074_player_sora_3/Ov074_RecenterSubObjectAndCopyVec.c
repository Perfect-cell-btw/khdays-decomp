/* When the effect node is in its visible state, places it at the character's mark point, turns it
 * with the character and draws it. */

struct w3 { int a, b, c; };
extern void Ov074_GetMarkPoint(void *out, int this_);
extern void Scene_DrawNode(int p);

void Ov074_RecenterSubObjectAndCopyVec(int this_, int arg1) {
    struct w3 tmp;
    if (*(int *)arg1 != 2) return;
    Ov074_GetMarkPoint(&tmp, this_);
    *(unsigned short *)(arg1 + 0x80) =
        (unsigned short)((unsigned short)(*(unsigned short *)(*(int *)(this_ + 0x20) + 0x80) - 0x8000) + 0x8000);
    *(unsigned short *)(arg1 + 4) |= 0x20;
    *(struct w3 *)(arg1 + 0xa8) = tmp;
    Scene_DrawNode(arg1 + 4);
}
