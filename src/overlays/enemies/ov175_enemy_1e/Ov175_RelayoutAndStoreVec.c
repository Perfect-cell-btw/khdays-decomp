/* Re-lays the node out, stores the vector and sets flag bit 0. */

#include "nitro/fx.h"

extern int Ov107_MoveNodeAndRelayout();

struct Obj {
    char _pad0[0x60];
    unsigned short flags : 8;   /* 0x60, bits [7:0] */
    unsigned short _bf : 8;     /* 0x60, bits [15:8] */
    char _pad1[0x390 - 0x62];
    VecFx32 vec;            /* 0x390 */
};

void Ov175_RelayoutAndStoreVec(struct Obj *this, int arg1, VecFx32 *src) {
    Ov107_MoveNodeAndRelayout(this);
    this->vec = *src;
    this->_bf |= (unsigned short)1;
}
