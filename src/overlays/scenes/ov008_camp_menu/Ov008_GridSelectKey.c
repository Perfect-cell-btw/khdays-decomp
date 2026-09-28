/* Ov008_GridSelectKey -- move the grid selection to key param_2 (ignored while the grid is busy,
 * obj+0x30). Only acts if the key resolves (Ov008_ListHasItems) and differs from the current
 * selection (obj+0x70): applies it and fires UI event 2. */
extern int  Ov008_ListHasItems(int obj, unsigned int key);
extern void Ov008_Menu_ChangePage(int obj, unsigned int key);
extern void PlaySound(int a, int b);

void Ov008_GridSelectKey(int param_1, unsigned int param_2) {
    if (*(int *)(param_1 + 0x30) != 0) {
        return;
    }
    if (Ov008_ListHasItems(param_1, param_2) != 0 &&
        param_2 != *(unsigned int *)(param_1 + 0x70)) {
        Ov008_Menu_ChangePage(param_1, param_2);
        PlaySound(0, 2);
    }
}
