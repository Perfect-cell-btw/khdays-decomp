extern void Ov082_UpdateController(void *arg);

void Ov082_ForwardComputeAimAngle(char *base) {
    Ov082_UpdateController(base + 0x2ca8);
}
