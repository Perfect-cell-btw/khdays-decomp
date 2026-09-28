/* Initialises a slot from its source: marks it used and records the source, its id and its value.
 */

void Ov026_InitSlotFromSource(char *obj, char *src) {
    *(int *)obj = 1;
    *(int *)(obj + 0xc) = (int)src;
    *(int *)(obj + 4) = *(int *)(src + 0x14);
    *(int *)(obj + 8) = *(int *)(src + 0x88);
}
