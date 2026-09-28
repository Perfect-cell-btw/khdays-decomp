extern void Ov030_RebindEmitterSlots(void *this, int arg);

void Ov030_beginState5(char *this) {
    Ov030_RebindEmitterSlots(this, 2);
    *(signed char *)(this + 0x12c) = 5;
    *(int *)(this + 0x130) = 0;
}
