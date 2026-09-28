extern int Ov107_UnlinkNodeFromOwner();

void Ov187_UnlinkHeldNode(int *r0) {
    Ov107_UnlinkNodeFromOwner(r0[0xe4]);
    r0[0xe4] = 0;
}
