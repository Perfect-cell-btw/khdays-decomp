/* Unlinks a slot's OAM entry when it is linked and clears its linked bit. */

extern void func_02031df0(void *ptr, void *arg);

void Slot_UnlinkIfLinked(int *pPtr, int index) {
    unsigned char *ptr = (unsigned char *)pPtr;
    int offset;
    int *flags;

    if (index < 0) {
        return;
    }

    offset = index * 0x8c;
    flags = (int *)(ptr + 0x7c + offset);
    if (((unsigned int)(*flags << 31) >> 31) == 0) {
        return;
    }

    func_02031df0(ptr, ptr + 4 + offset);
    *flags &= ~1;
}
