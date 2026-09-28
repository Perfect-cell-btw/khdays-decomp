/* Returns the indexed word of a table inside the object a global points to. */

extern int data_ov002_0207fa14;

int Ov002_GetPieceOwner(int arg0) {
    return *(int *)(*(int *)&data_ov002_0207fa14 + arg0 * 4 + 0x1c);
}
