/* Panel callback: runs ComputeAimAngle on the controller at +0x2ca8. */

extern void Ov063_UpdateController(void *arg);

void Ov063_ForwardComputeAimAngle(char *base) {
    Ov063_UpdateController(base + 0x2ca8);
}
