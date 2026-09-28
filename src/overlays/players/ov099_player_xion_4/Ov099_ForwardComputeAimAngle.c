/* Panel callback: runs ComputeAimAngle on the controller at +0x2ca8. */

extern void Ov099_TickActor(void *arg);

void Ov099_ForwardComputeAimAngle(char *base) {
    Ov099_TickActor(base + 0x2ca8);
}
