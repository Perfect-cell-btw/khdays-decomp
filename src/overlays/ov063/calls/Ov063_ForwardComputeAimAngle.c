extern void Ov063_UpdateController(void *arg);

void Ov063_ForwardComputeAimAngle(char *base) {
    Ov063_UpdateController(base + 0x2ca8);
}
