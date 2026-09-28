extern int Ov002_GetCtxTableByte(int slot);
extern char data_ov002_0207fa28;

extern void Entity_Activate(void *actor, int nList);

/* Same as Ov002_ResetSlotActorPose but binds the resolved model id instead. */
void Ov002_BindSlotActorModel(int slot) {
    int off = slot * 0x184;
    int id;
    if (*(int *)(*(char **)((char *)&data_ov002_0207fa28 + 4) + off + 0xc4) != 0) {
        id = Ov002_GetCtxTableByte(slot);
        if (id >= 0) {
            Entity_Activate(*(char **)((char *)&data_ov002_0207fa28 + 4) + 0xb8 + off,
                          (unsigned short)id);
        }
    }
}
