extern void Ov082_RebindEmitterSlots(void *this, int arg);

void Ov082_beginState5(char *this) {
    Ov082_RebindEmitterSlots(this, 2);
    *(signed char *)(this + 0x12c) = 5;
    *(int *)(this + 0x130) = 0;
}
