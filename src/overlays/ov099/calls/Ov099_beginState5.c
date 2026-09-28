extern void Ov099_RebindEmitterSlots(void *this, int arg);

void Ov099_beginState5(char *this) {
    Ov099_RebindEmitterSlots(this, 2);
    *(signed char *)(this + 0x12c) = 5;
    *(int *)(this + 0x130) = 0;
}
