extern void SetSubitemState();
extern void SetIndexedSlot();
extern void Ov132_stateSubitemStateTransition();

void Ov132_ConfigureActorUnlessBusy(int this_) {
    int m = *(int *)(*(int *)(this_ + 4) + 4);
    if (*(unsigned char *)(m + 0xad)) return;
    SetSubitemState(m, 0, 1, 1);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov132_stateSubitemStateTransition);
}
