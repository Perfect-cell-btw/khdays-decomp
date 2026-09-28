/* Word idx of the object list block. */

extern int data_ov002_0207fa20;

int Ov002_List_GetWord(int arg0) {
    return ((int *)(*(int *)((char *)&data_ov002_0207fa20 + 4)))[arg0];
}
