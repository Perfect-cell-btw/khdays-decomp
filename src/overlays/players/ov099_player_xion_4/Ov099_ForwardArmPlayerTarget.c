/* Panel callback (+0x664+0x24): runs ArmPlayerTarget on the controller at +0x2ca8. */

extern void Ov099_ArmPlayerTarget(void *arg, int r1);

void Ov099_ForwardArmPlayerTarget(char *base, int r1) {
    Ov099_ArmPlayerTarget(base + 0x2ca8, r1);
}
