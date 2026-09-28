/* Returns a word of the field state (the object data_ov002_0207f62c points to). */

extern int data_ov002_0207f62c;

int Ov002_Field_GetState(void) {
    return *(int *)(*(int *)((char *)&data_ov002_0207f62c + 4) + 0xc);
}
