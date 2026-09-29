/* Returns the display engine of a display-object list: 1 (main) or 2 (sub) from +0x4604; any other
 * value returns the list pointer unchanged. */

int DispObjList_GetEngine(int list) {
    if (*(int *)(list + 0x4604) != 1) {
        if (*(int *)(list + 0x4604) == 2) list = 2;
        return list;
    }
    return 1;
}
