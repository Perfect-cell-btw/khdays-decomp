struct hw60 { unsigned short lo : 8; unsigned short hi : 8; };
struct flagword { unsigned int f8 : 8; };

extern void Ov107_BuildAndSendUpdate();
extern void SetIndexedSlot(void *obj, int idx, void *value);

void Ov131_ConfigHw60FlagsBeginAction4a(char *obj) {
    int *state = *(int **)(obj + 4);
    unsigned int h;
    ((struct hw60 *)(*state + 0x60))->hi &= ~1;
    *(unsigned short *)(*state + 0x1ae) |= 3;
    h = *(unsigned short *)(*state + 0x60);
    *(unsigned short *)(*state + 0x60) =
        (h & ~0xff00) | (((((h << 0x10) >> 0x18) | 0x86) << 0x18) >> 0x10);
    ((struct flagword *)(*(int *)(*state + 0x388) + 8))->f8 &= ~1;
    Ov107_BuildAndSendUpdate(*state, 0, 0x4a, state[0x11]);
    *(signed char *)(*state + 0x1c7) = 0;
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), 0);
}
