typedef struct { int w[11]; } Blk44;

extern void Ov107_ProcessObjectTick(char *self, int a);

void Ov213_TickSyncXformFirst(char *self, int a) {
    *(Blk44 *)(*(char **)(self + 0x38c) + 0x10) = *(Blk44 *)(self + 0xa0);
    Ov107_ProcessObjectTick(self, a);
}
