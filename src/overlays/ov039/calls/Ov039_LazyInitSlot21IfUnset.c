extern int data_ov039_020b5600;
extern int Ov022_ActorSetState();

int Ov039_LazyInitSlot21IfUnset(int this_) {
    int r = 0;
    if (*(int *)(data_ov039_020b5600 + 0x2fe4) == 0) {
        r = Ov022_ActorSetState(this_, 0x21);
    }
    return r;
}
