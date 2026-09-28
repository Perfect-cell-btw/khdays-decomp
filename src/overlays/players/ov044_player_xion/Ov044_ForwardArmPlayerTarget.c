/* Panel callback (+0x664+0x24): runs ArmPlayerTarget on the controller at +0x2ca8. */

extern void Ov044_ArmPlayerTarget(void *arg, int r1);

void Ov044_ForwardArmPlayerTarget(char *base, int r1) {
    Ov044_ArmPlayerTarget(base + 0x2ca8, r1);
}
