/* Set the list's shared mode byte at +0x7a and push the same mode into every row,
 * addressing each row's entry through its byte id at +0x10. The row count at
 * +0x50 is re-read on every iteration rather than cached -- that is the ROM. */
extern int Ov002_GetModuleSlot(int listId);
extern int Ov002_MulTagAtField4ePlusField54(int list, int row);
extern void Ov002_List_SetBit(int entry, int mode);

void Ov002_SetListRowMode(int listId, int mode) {
    char *list = (char *)Ov002_GetModuleSlot(listId);
    int i = 0;

    list[0x7a] = (char)mode;

    while (i < *(unsigned short *)(list + 0x50)) {
        Ov002_List_SetBit(*(unsigned char *)(Ov002_MulTagAtField4ePlusField54((int)list, i) + 0x10), mode);
        i++;
    }
}
