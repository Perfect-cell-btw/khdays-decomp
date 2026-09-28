/* Build the base object, then attach four sub-objects at +0x88..+0x94. */
extern int Ov009_FindEntryById(int self, int arg);
void Ov009_BuildNodeWithChildren(int param_1, int param_2) {
    int obj = Ov009_FindEntryById(param_1, *(int *)param_2);
    *(int *)(obj + 0x88) = Ov009_FindEntryById(param_1, *(int *)(param_2 + 0x40));
    *(int *)(obj + 0x8c) = Ov009_FindEntryById(param_1, *(int *)(param_2 + 0x44));
    *(int *)(obj + 0x90) = Ov009_FindEntryById(param_1, *(int *)(param_2 + 0x48));
    *(int *)(obj + 0x94) = Ov009_FindEntryById(param_1, *(int *)(param_2 + 0x4c));
}
