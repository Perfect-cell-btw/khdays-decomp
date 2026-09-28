/* Stores a byte into the root field object a global points to. */

extern int data_ov002_0207fa00;

void Ov002_World_SetByte8D68(int arg0) {
    *(char *)(*(int *)&data_ov002_0207fa00 + 0x8d68) = arg0;
}
