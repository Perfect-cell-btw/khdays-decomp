extern void Ov063_RebindEmitterSlots(void *this, int arg);

void Ov063_beginState5(char *this) {
    Ov063_RebindEmitterSlots(this, 2);
    *(signed char *)(this + 0x12c) = 5;
    *(int *)(this + 0x130) = 0;
}
