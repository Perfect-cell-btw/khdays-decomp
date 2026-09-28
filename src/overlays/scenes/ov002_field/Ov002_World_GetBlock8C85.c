/* Returns the address of a block inside the object a global points to. */

extern int data_ov002_0207fa00;

int Ov002_World_GetBlock8C85(void) {
    return *(int *)&data_ov002_0207fa00 + 0x8c85;
}
