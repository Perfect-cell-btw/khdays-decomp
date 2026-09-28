/* Re-lays the node out, stores the vector and sets flag bit 0. */

extern int Ov107_MoveNodeAndRelayout();

struct Vec3 {
    int x;
    int y;
    int z;
};

struct Obj {
    char _pad0[0x60];
    unsigned short flags : 8;   /* 0x60, bits [7:0] */
    unsigned short _bf : 8;     /* 0x60, bits [15:8] */
    char _pad1[0x390 - 0x62];
    struct Vec3 vec;            /* 0x390 */
};

void Ov125_RelayoutAndStoreVec(struct Obj *this, int arg1, struct Vec3 *src) {
    Ov107_MoveNodeAndRelayout(this);
    this->vec = *src;
    this->_bf |= (unsigned short)1;
}
