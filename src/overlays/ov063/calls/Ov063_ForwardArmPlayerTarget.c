extern void Ov063_ArmPlayerTarget(void *arg);

void Ov063_ForwardArmPlayerTarget(char *base) {
    Ov063_ArmPlayerTarget(base + 0x2ca8);
}
