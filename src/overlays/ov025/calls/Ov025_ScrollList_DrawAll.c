extern void Ov025_ScrollList_DrawRow(int arg0, int arg1, int arg2);

void Ov025_ScrollList_DrawAll(int arg0) {
    int total = *(int *)(arg0 + 0x2d0);
    int chunk = total / 16;
    int i;

    for (i = 0; i < 11; i++) {
        Ov025_ScrollList_DrawRow(arg0, i, i + chunk);
    }

    *(int *)(arg0 + 0x14) = 1;
}
