/* Panel callback (+0x664+0x24): runs ArmPlayerTarget on the controller at +0x2ca8. */

extern void Ov082_ArmPlayerTarget(void *arg, int r1);

void Ov082_ForwardArmPlayerTarget(char *base, int r1) {
    Ov082_ArmPlayerTarget(base + 0x2ca8, r1);
}
