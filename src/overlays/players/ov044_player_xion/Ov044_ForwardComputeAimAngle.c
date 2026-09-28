/* Panel callback: runs ComputeAimAngle on the controller at +0x2ca8. */

extern void Ov044_ComputeAimAngle(void *arg);

void Ov044_ForwardComputeAimAngle(char *base) {
    Ov044_ComputeAimAngle(base + 0x2ca8);
}
