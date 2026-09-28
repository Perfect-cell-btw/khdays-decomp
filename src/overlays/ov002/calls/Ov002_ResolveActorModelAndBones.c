extern int Ov002_GetCtxTableByte(int slot);
extern void EntityMgr_ProbeGround(unsigned short id, void *a, void *b);

/* Resolves the actor's model id on the first tick and, if it has a bone table, binds it. */
int Ov002_ResolveActorModelAndBones(char *self, int phase) {
    int id;
    if (phase == 0) {
        *(short *)(self + 0x1c) = (short)Ov002_GetCtxTableByte(*(short *)(self + 0x1a));
        id = *(short *)(self + 0x1c);
        if (id >= 0 && *(signed char *)(self + 0x38) != 0) {
            EntityMgr_ProbeGround((unsigned short)id, self + 0x38, self + 0x2c);
        }
    }
    return 0;
}
