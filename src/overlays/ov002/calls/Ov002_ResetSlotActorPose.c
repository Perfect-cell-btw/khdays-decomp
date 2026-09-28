extern int Ov002_GetCtxTableByte(int slot);
extern char data_ov002_0207fa28;

extern void Entity_Deactivate(void *actor);

/* Kicks the slot's actor into its default pose, if the slot is occupied and mapped. */
void Ov002_ResetSlotActorPose(int slot) {
    int off = slot * 0x184;
    if (*(int *)(*(char **)((char *)&data_ov002_0207fa28 + 4) + off + 0xc4) != 0) {
        if (Ov002_GetCtxTableByte(slot) >= 0) {
            Entity_Deactivate(*(char **)((char *)&data_ov002_0207fa28 + 4) + 0xb8 + off);
        }
    }
}
