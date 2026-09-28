/* Walks the current widget's sibling chain and returns the first sibling whose kind (+0x4c of its
 * descriptor) is 0xe, or 0 when there is none. */
extern int Ov002_GetSlotTableByte(int);
extern int Ov002_List_GetWord(int id);
int Ov002_FindSiblingOfKindE(int arg0) {
    int p = Ov002_List_GetWord((unsigned short)Ov002_GetSlotTableByte(arg0));
    while (p != 0) {
        if (*(unsigned short *)(*(int *)(p + 8) + 0x4c) == 0xe) {
            return p;
        }
        p = *(int *)(p + 4);
    }
    return p;
}
