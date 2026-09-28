/* Returns a word of the field state (the object data_ov002_0207f62c points to). */

extern int data_ov025_020b5744;

int Ov025_GetCtxField9768(void) {
    return *(int *)(*(int *)((char *)&data_ov025_020b5744 + 4) + 0x9768);
}
