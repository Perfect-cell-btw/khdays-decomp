extern void SetSubitemState();
extern void SetIndexedSlot();

void Ov161_ConfigureSubObjectTwiceThenAdvance(int this_) {
    int node = *(int *)(this_ + 4);
    if (*(unsigned char *)(*(int *)(node + 4) + 0xad) != 0) return;
    SetSubitemState(*(int *)(node + 4), 2, 1, 1);
    SetSubitemState(*(int *)(node + 4), 0, 1, 1);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), 0);
}
