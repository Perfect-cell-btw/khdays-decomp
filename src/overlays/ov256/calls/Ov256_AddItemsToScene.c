/* Scene hook of the ov256 enemy: adds its two +0x434 items and the five +0x43c items to the
 * scene (arg 1) and chains to the common handler. */
extern void Ov107_InitObjectFromSource(int obj, int arg1);
extern void Ov107_HandleRegionEvent(int obj, int arg1);

void Ov256_AddItemsToScene(int *list, int target) {
    int i;
    for (i = 0; i < 2; i++)
        Ov107_InitObjectFromSource(target, list[i + 0x10d]);
    for (i = 0; i < 0x5; i++)
        Ov107_InitObjectFromSource(target, list[i + 0x10f]);
    Ov107_HandleRegionEvent((int)list, target);
}
