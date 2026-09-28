/* Returns a word of the field state (the object data_ov002_0207f62c points to). */

extern int data_ov025_020b5744;

int Ov025_GetCtxObject95c0(void) {
    return *(int *)(*(int *)((char *)&data_ov025_020b5744 + 4) + 0x95c0);
}
