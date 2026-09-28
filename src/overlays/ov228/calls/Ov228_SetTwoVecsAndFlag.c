/* Setter: hand the caller's vector (param v) to Ov107_MoveNodeAndRelayout, store the second
 * triple (param_5..7) into owner fields +0x398/+0x39c/+0x3a0, and set owner hw60 hi bit 1. */
struct vec { int x, y, z; };
extern void Ov107_MoveNodeAndRelayout(int owner, struct vec *v);
void Ov228_SetTwoVecsAndFlag(int param_1, struct vec v, struct vec v2) {
    Ov107_MoveNodeAndRelayout(param_1, &v);
    *(struct vec *)(param_1 + 0x398) = v2;
    {
        unsigned short hv = *(unsigned short *)(param_1 + 0x60);
        *(unsigned short *)(param_1 + 0x60) =
            (unsigned short)((hv & ~0xff00) | (((((unsigned int)hv << 0x10) >> 0x18 | 1) << 0x18) >> 0x10));
    }
}
