extern int Ov025_ListHasItems();
extern void Ov025_Menu_ChangePage();
extern void PlaySound();

void Ov025_AdvanceSlotIfMatch(int arg0, unsigned int arg1, int arg2, int arg3) {
    int s = *(int *)(arg0 + 0x30);
    if (s != 0) return;
    if (Ov025_ListHasItems(arg0, arg1)) {
        if (arg1 != *(unsigned int *)(arg0 + 0x70)) {
            Ov025_Menu_ChangePage(arg0, arg1);
            PlaySound(0, 2);
        }
    }
}
