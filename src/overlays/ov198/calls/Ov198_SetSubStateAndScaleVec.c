extern void ScaleVec3Fx12();

struct w3 { int a, b, c; };

void Ov198_SetSubStateAndScaleVec(int this_, struct w3 *src) {
    *(signed char *)(*(int *)this_ + 0x1c7) = 1;
    *(struct w3 *)(this_ + 0x14) = *src;
    ScaleVec3Fx12(0x800, this_ + 0x14, this_ + 8);
}
