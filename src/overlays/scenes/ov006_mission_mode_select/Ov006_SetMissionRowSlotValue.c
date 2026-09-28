/* Ov006_SetMissionRowSlotValue -- char select: set roster slot `slot`'s payload and visibility.
 * The slot's value lives at OBJ+0x9510, its cell handle at OBJ+0x9704 and its current
 * visibility at OBJ+0x9534, all indexed by slot. When the visibility actually changes the
 * cell is bound into (Slot_ForwardToEntry + Slot_ClearFlagBit1) or dropped from (Slot_SetFlagBit1) the
 * renderer list at OBJ+0x4a8c. Returns 0 if the manager context is gone. */
extern void Slot_ForwardToEntry(int list, int cell, int a);
extern void Slot_ClearFlagBit1(int list, int cell);
extern void Slot_SetFlagBit1(int list, int cell);
extern int *data_ov006_02056664;

int Ov006_SetMissionRowSlotValue(int slot, int value, int visible) {
    char *obj;
    int cell;
    int was;

    if (data_ov006_02056664 == 0) {
        return 0;
    }
    *(int *)((char *)data_ov006_02056664 + slot * 4 + 0x9510) = value;
    obj = (char *)data_ov006_02056664;
    cell = *(int *)(obj + slot * 4 + 0x9704);
    if (cell != 0) {
        was = *(int *)(obj + slot * 4 + 0x9534);
        if (was == 0 && visible != 0) {
            Slot_ForwardToEntry((int)(obj + 0x4a8c), cell, 0);
            Slot_ClearFlagBit1((int)((char *)data_ov006_02056664 + 0x4a8c),
                          *(int *)((char *)data_ov006_02056664 + slot * 4 + 0x9704));
        } else if (was != 0 && visible == 0) {
            Slot_SetFlagBit1((int)(obj + 0x4a8c), cell);
        }
    }
    *(int *)((char *)data_ov006_02056664 + slot * 4 + 0x9534) = visible;
    return 1;
}
