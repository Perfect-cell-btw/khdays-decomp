/* Stores the root context's word at +0x85ac. */

extern int data_ov002_0207fa00;

void Ov002_SetRootField85ac(int arg0, int arg1) {
    *(int *)(*(int *)&data_ov002_0207fa00 + 0x85ac) = arg1;
}
