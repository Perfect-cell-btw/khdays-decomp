/* Stores the vector at +0x394, moves the node and re-lays it out, and sets bit 0 of the high byte
 * of its flags (+0x60). */

extern void Ov107_MoveNodeAndRelayout();

struct w3 { int a, b, c; };

void Ov123_StoreVec3ThenSetupAndSetHw60(int this_, int arg1, struct w3 *src) {
    unsigned short *p;
    unsigned int h;
    *(struct w3 *)(this_ + 0x394) = *src;
    Ov107_MoveNodeAndRelayout(this_, arg1);
    p = (unsigned short *)(this_ + 0x60);
    h = *p;
    *p = h & ~0xff00 | (((((unsigned int)h << 0x10) >> 0x18 | 1) << 0x18) >> 0x10);
}
