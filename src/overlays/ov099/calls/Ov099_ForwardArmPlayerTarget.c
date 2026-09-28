extern void Ov099_ArmPlayerTarget(void *arg);

void Ov099_ForwardArmPlayerTarget(char *base) {
    Ov099_ArmPlayerTarget(base + 0x2ca8);
}
