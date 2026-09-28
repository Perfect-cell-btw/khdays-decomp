struct bf { unsigned b : 8; };
struct hw60 { unsigned short lo : 8, hi : 8; };
extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern void SetIndexedSlot();

void Ov132_ConfigHw60FlagsBeginAction4a(int this_) {
    int holder = *(int *)(this_ + 4);
    ((struct hw60 *)(*(int *)holder + 0x60))->hi &= ~1;
    *(unsigned short *)(*(int *)holder + 0x1ae) |= 3;
    {
        unsigned short *p = (unsigned short *)(*(int *)holder + 0x60);
        unsigned int u = *p;
        *p = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 0x86) << 0x18) >> 0x10));
    }
    ((struct bf *)(*(int *)(*(int *)holder + 0x388) + 8))->b &= ~1;
    Ov107_BuildAndSendUpdate(*(int *)holder, 0, 0x4a, *(int *)(holder + 0x44));
    *(signed char *)(*(int *)holder + 0x1c7) = 0;
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), 0);
}
