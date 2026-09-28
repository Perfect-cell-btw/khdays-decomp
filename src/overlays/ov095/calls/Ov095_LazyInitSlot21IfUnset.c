extern int data_ov095_020bcba0;
extern int Ov022_ActorSetState();

int Ov095_LazyInitSlot21IfUnset(int this_) {
    int r = 0;
    if (*(int *)(data_ov095_020bcba0 + 0x2fe4) == 0) {
        r = Ov022_ActorSetState(this_, 0x21);
    }
    return r;
}
