/* SetSubitemState on model tracks 0, 2, 4 and 1 with the actor's stored animation (+0x310), then
 * RefreshObjectCallbacks. */

extern int SetSubitemState();
extern int RefreshObjectCallbacks();

struct S {
    char pad300[0x310];
    signed char b310;
    unsigned char bit0 : 1;
    unsigned char rest : 7;
    char pad312[0x72];
    void *p384;
};

int Ov209_Model_ReapplyTracks(struct S *s) {
    SetSubitemState(s->p384, 0, s->b310, s->bit0);
    SetSubitemState(s->p384, 2, s->b310, s->bit0);
    SetSubitemState(s->p384, 4, s->b310, s->bit0);
    SetSubitemState(s->p384, 1, s->b310, s->bit0);
    return RefreshObjectCallbacks(s->p384, 0);
}
