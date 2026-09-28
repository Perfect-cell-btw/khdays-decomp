extern int Ov002_GetSlotTableByte(int);
extern int Ov002_List_GetWord(unsigned short id);
/* Walk the current widget's sibling chain, stopping at the first one whose kind (+0x4c of its
 * descriptor) is 0xe. */
void Ov002_FindSiblingOfKindE(int arg0) {
    int p = Ov002_List_GetWord((unsigned short)Ov002_GetSlotTableByte(arg0));
    while (p != 0) {
        if (*(unsigned short *)(*(int *)(p + 8) + 0x4c) == 0xe) {
            return;
        }
        p = *(int *)(p + 4);
    }
}
