extern int Ov002_GetCtxTableByte(int slot);
extern signed char Ov002_GetCtxModeByte(int id);
extern int Ov002_GetSlotTableByte(int id);
extern char data_ov002_0207fa28;

/* Records whether any spawn slot is currently running state 9 of routine 3, and clears the
 * pending-request field. */
void Ov002_UpdateAnySlotBusyFlag(void) {
    int found = 0;
    int i;
    int id;
    for (i = 0; i < 0x18; i++) {
        id = Ov002_GetCtxTableByte(i);
        if (id >= 0 && Ov002_GetCtxModeByte(id) == 3 && Ov002_GetSlotTableByte(id) == 9) {
            found = 1;
        }
    }
    *(int *)(*(char **)((char *)&data_ov002_0207fa28 + 4) + 0x2524) = found;
    *(int *)(*(char **)((char *)&data_ov002_0207fa28 + 4) + 0x58) = 0;
}
