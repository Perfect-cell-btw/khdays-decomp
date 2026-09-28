/* Re-lays the node out, stores the vector at +0x394 and sets flags60 bit 8. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int Ov107_MoveNodeAndRelayout();

struct Vec3 {
    u32 x, y, z;
};

union F {
    u16 w;
    struct {
        u16 lo : 8;
        u16 hi : 8;
    } bf;
};

struct Obj {
    u8 pad0[0x60];
    union F f60;
    u8 pad62[0x394 - 0x62];
    struct Vec3 field_0x394;
};

void Ov149_RelayoutAndStoreVec(struct Obj *a, int b, struct Vec3 *src) {
    Ov107_MoveNodeAndRelayout(a, b);
    a->field_0x394 = *src;
    a->f60.w = (u16)((a->f60.w & ~0xff00) | (((a->f60.bf.hi | 1) & 0xff) << 8));
}
