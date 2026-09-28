/* Moves the node and re-lays it out, stores the vector at +0x38c and sets bit 0 of the high byte of
 * its flags (+0x60). */

extern void Ov107_MoveNodeAndRelayout();

struct w3 { int a, b, c; };

void Ov142_StoreVec3AndSetHw60HighBit0(int this_, int arg1, struct w3 *src) {
    unsigned short *p;
    unsigned int h;
    Ov107_MoveNodeAndRelayout(this_, arg1);
    *(struct w3 *)(this_ + 0x38c) = *src;
    p = (unsigned short *)(this_ + 0x60);
    h = *p;
    *p = h & ~0xff00 | (((((unsigned int)h << 0x10) >> 0x18 | 1) << 0x18) >> 0x10);
}
