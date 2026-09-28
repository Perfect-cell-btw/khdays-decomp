/* ORs bits into the low 16-bit field of node+0xc, preserving the high half. */

struct NodeWordC {
    unsigned int lo : 16;
    unsigned int hi : 16;
};

void Ov107_OrLowFlags(int node, unsigned int bits) {
    ((struct NodeWordC *)(node + 0xc))->lo |= bits;
}
