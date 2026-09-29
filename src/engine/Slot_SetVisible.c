/* Shows or hides a slot (its visible bit; negative indices are ignored). */

struct Inner {
    unsigned int b0 : 2;
    unsigned int flag : 1;
    unsigned int rest : 29;
    char pad[0x8c - 4];
};

void Slot_SetVisible(unsigned char *pBase, int index, int value) {
    int *base = (int *)pBase;
    struct Inner *p;
    if (index < 0) return;
    p = (struct Inner *)((char *)base + 0x7c);
    p[index].flag = (value != 0);
}
