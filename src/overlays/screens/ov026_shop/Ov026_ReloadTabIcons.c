extern char *data_ov026_02091368;
extern int Ov026_FindEntryByTag(void *p, unsigned int id);
extern void Ov026_TagTracker_InvokeCallback(void *p, int cell);

/* Reloads every icon of the current tab except the selected one, then the selected one last so it
 * ends up on top. */
void Ov026_ReloadTabIcons(void) {
    char *st = *(char **)&data_ov026_02091368;
    char *tab = st + 0xc3b8;
    int i;
    int count;
    switch (*(int *)(st + 0xc250)) {
    case 2:
        count = 6;
        break;
    case 3:
        count = 2;
        break;
    default:
        count = 8;
        break;
    }
    for (i = 0; i < count; i++) {
        if (i != *(int *)(tab + 8)) {
            Ov026_TagTracker_InvokeCallback(st + 0x10, Ov026_FindEntryByTag(st + 0x10,
                (unsigned short)(*(int *)(tab + 4) + i)));
        }
    }
    Ov026_TagTracker_InvokeCallback(st + 0x10, Ov026_FindEntryByTag(st + 0x10,
        (unsigned short)(*(int *)tab + *(int *)(tab + 8))));
}
