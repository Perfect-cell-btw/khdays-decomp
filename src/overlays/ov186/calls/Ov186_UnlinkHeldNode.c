extern int Ov107_UnlinkNodeFromOwner();

void Ov186_UnlinkHeldNode(int *r0) {
    Ov107_UnlinkNodeFromOwner(r0[0xe4]);
    r0[0xe4] = 0;
}
