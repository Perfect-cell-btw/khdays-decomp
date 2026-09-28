/* Copies the transform into the model, then runs the object tick. */

typedef struct { int w[11]; } Blk44;

extern int Ov107_ProcessObjectTick(void *self, int a);

int Ov273_TickSyncXformFirst(char *self, int a) {
    *(Blk44 *)(*(char **)(self + 0x38c) + 0x10) = *(Blk44 *)(self + 0xa0);
    return Ov107_ProcessObjectTick(self, a);
}
