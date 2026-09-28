/* True when the object (not -1) has a descriptor whose +0x38 has bit 0x2000 set. */

int Ov002_IsObjectFlag2000Set(int arg0) {
    if (arg0 == -1) {
        return 0;
    }
    int p = *(int *)(arg0 + 0x20);
    return p != 0 ? (*(int *)(p + 0x38) & 0x2000) : 0;
}
