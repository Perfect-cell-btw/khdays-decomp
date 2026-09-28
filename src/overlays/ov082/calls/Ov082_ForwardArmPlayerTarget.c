extern void Ov082_ArmPlayerTarget(void *arg);

void Ov082_ForwardArmPlayerTarget(char *base) {
    Ov082_ArmPlayerTarget(base + 0x2ca8);
}
