extern void Scene_DrawNode();

struct b1 { unsigned char b : 1; };

void Ov045_ForwardArg1IfStateInRangeAndFlag(int this_, int arg1) {
    signed char s = *(signed char *)arg1;
    if (s != 2 && s != 3 && s != 4) return;
    if (((struct b1 *)(this_ + 0x694))->b == 0) return;
    Scene_DrawNode(arg1 + 4);
}
