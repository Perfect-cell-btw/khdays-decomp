extern void Ov017_ItemGivenStep();
extern void Ov002_DoneTick();

void *Ov017_GetCallbackForState1b4(int this_) {
    unsigned char x = *(unsigned char *)(this_ + 0x1b4);
    if (x == 5) {
        return Ov017_ItemGivenStep;
    }
    if (x == 7) {
        return Ov002_DoneTick;
    }
    return 0;
}
