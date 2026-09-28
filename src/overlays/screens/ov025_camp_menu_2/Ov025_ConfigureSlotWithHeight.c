/* Moves entry 3 next to the first valid slot of an entry. */

extern int Ov025_GetContext();
extern int Ov025_ApplyFirstValidSlot();
extern int Ov025_FindEntryById();
extern void Ov025_ReleaseTwoSlotsEx();

void Ov025_ConfigureSlotWithHeight(int arg0) {
    int a = Ov025_GetContext();
    int e = Ov025_ApplyFirstValidSlot(a, arg0);
    int local[2];
    local[0] = 0x78000;
    local[1] = *(int *)(e + 4) + 0x8000;
    Ov025_ReleaseTwoSlotsEx(a, Ov025_FindEntryById(a, 3), local);
}
