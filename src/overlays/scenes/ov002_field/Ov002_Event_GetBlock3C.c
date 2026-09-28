/* Returns the address of a block inside the object a global points to. */

extern int data_ov002_0207fa14;

int Ov002_Event_GetBlock3C(void) {
    return *(int *)&data_ov002_0207fa14 + 0x3c;
}
