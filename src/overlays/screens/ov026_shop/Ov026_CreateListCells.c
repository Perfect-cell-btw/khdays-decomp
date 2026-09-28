extern char *data_ov026_02091368;
extern int Ov026_CreateMissionCell(int handle, int kind, int a, int b, int c);

/* Creates the list frame cell, the scrollbar cell and the twelve row cells. */
void Ov026_CreateListCells(void) {
    char *st = *(char **)&data_ov026_02091368;
    char *list = st + 0xc57c;
    int handle = *(int *)(st + 0xbfb0);
    int i;
    *(int *)(st + 0xc57c) = Ov026_CreateMissionCell(handle, 0xc, 0, 0, 0);
    *(int *)(list + 4) = Ov026_CreateMissionCell(handle, 0xe, 0, 0, 0);
    for (i = 0; i < 0xc; i++) {
        *(int *)(list + i * sizeof(int) + 8) = Ov026_CreateMissionCell(handle, 0xd, 0, 0, 0);
    }
}
