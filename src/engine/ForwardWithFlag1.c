/* Adds an item to a save slot with the flag set (SaveSlot_AddItem). */

extern int SaveSlot_AddItem();

int ForwardWithFlag1(int arg0, int arg1) {
    return SaveSlot_AddItem(arg0, arg1, 1);
}
