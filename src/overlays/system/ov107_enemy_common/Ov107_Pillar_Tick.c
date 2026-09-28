/* Pillar tick: flags (+0x1e4 bit 4) when the source's counter changed or it is busy, then the base
 * post tick. */

extern void Ov107_AiState_PostTick(void *self);

void Ov107_Pillar_Tick(char *self) {
    *(int *)(self + 0x1e4) = 0;
    char *p = *(char **)(self + 0x18c);
    if (p != 0) {
        int v = *(int *)(p + 0x2abc);
        if (*(int *)(self + 0x1b8) != v || (*(unsigned short *)(p + 0x18) & 0x803) != 0) {
            *(int *)(self + 0x1b8) = v;
            *(int *)(self + 0x1e4) |= 0x10;
        } else {
            *(int *)(self + 0x1e4) &= ~0x10;
        }
    }
    Ov107_AiState_PostTick(self);
}
