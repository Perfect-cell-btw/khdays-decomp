/* Returns 0 if the global slot at *globalData+0x2fe4 is already set; otherwise returns
 * Ov022_ActorSetState(this, 0x21). */

extern int data_ov078_020ba4e0;
extern int Ov022_ActorSetState();

int Ov078_LazyInitSlot21IfUnset(int this_) {
    int r = 0;
    if (*(int *)(data_ov078_020ba4e0 + 0x2fe4) == 0) {
        r = Ov022_ActorSetState(this_, 0x21);
    }
    return r;
}
