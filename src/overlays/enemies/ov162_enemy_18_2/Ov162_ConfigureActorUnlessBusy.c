/* AI step: unless the model is busy (+0xad), starts its track-0 animation and installs the
 * transition step. */

extern void SetSubitemState();
extern void SetIndexedSlot();
extern void Ov162_stateSubitemStateTransition();

void Ov162_ConfigureActorUnlessBusy(int this_) {
    int m = *(int *)(*(int *)(this_ + 4) + 4);
    if (*(unsigned char *)(m + 0xad)) return;
    SetSubitemState(m, 0, 1, 1);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov162_stateSubitemStateTransition);
}
