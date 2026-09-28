extern void Ov044_ArmPlayerTarget(void *arg);

void Ov044_ForwardArmPlayerTarget(char *base) {
    Ov044_ArmPlayerTarget(base + 0x2ca8);
}
