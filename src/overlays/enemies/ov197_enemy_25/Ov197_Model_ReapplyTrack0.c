/* SetSubitemState on model track 0 with the actor's stored animation (+0x310) and flag, then
 * RefreshObjectCallbacks. */

extern int SetSubitemState();
extern int RefreshObjectCallbacks();

struct S {
    char pad0[0x310];
    signed char b310;       /* +0x310 */
    unsigned char bit0 : 1; /* +0x311, bit 0 */
    char pad312[0x384 - 0x312];
    void *p384;             /* +0x384 */
};

void Ov197_Model_ReapplyTrack0(struct S *this) {
    SetSubitemState(this->p384, 0, this->b310, this->bit0);
    RefreshObjectCallbacks(this->p384, 0);
}
