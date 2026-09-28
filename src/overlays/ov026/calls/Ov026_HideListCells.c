extern char *data_ov026_02091368;
extern void Slot_SetVisible(int handle, int cell, int flag);

/* Hides the list frame and all twelve rows. */
void Ov026_HideListCells(void) {
    char *st = *(char **)&data_ov026_02091368;
    char *list = st + 0xc57c;
    int handle = *(int *)(st + 0xbfb0);
    int i;
    Slot_SetVisible(handle, *(int *)(st + 0xc57c), 0);
    Slot_SetVisible(handle, *(int *)(list + 4), 0);
    for (i = 0; i < 0xc; i++) {
        Slot_SetVisible(handle, *(int *)(list + i * sizeof(int) + 8), 0);
    }
}
