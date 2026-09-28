extern int Ov002_GetCtxTableByte(int slot);
extern void Ov002_DetachEntry(void *node);
extern void Ov002_Element_Deactivate(void *node);
extern void Ov002_ResetSlotActorPose(unsigned short slot);
extern char data_ov002_0207fa20;

/* Releases every object queued on each live spawn slot and then resets the slot's actor pose. */
void Ov002_ReleaseAllSlotObjects(void) {
    int i;
    char *node;
    char *next;
    for (i = 0; i < 0x18; i++) {
        if (Ov002_GetCtxTableByte(i) >= 0) {
            node = ((char **)*(char **)((char *)&data_ov002_0207fa20 + 4))[i];
            while (node != 0) {
                next = *(char **)(node + 4);
                Ov002_DetachEntry(node);
                Ov002_Element_Deactivate(node);
                node = next;
            }
            Ov002_ResetSlotActorPose((unsigned short)i);
        }
    }
}
