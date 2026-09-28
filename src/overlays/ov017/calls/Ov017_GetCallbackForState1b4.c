/* Returns a function pointer by state byte this[0x1b4]: 5 -> Ov017_ItemGivenStep, 7 ->
 * Ov002_DoneTick, else NULL. */

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
