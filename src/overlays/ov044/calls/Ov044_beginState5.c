extern void Ov044_RebindEmitterSlots(void *this, int arg);

void Ov044_beginState5(char *this) {
    Ov044_RebindEmitterSlots(this, 2);
    *(signed char *)(this + 0x12c) = 5;
    *(int *)(this + 0x130) = 0;
}
