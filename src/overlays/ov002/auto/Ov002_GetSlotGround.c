/* Returns the ground height (+0x10) of the slot's link record. */

extern int data_ov002_0207fa10;

int Ov002_GetSlotGround(int arg0) {
    int a = *(int *)&data_ov002_0207fa10;
    int b = *(int *)(a + 4);
    int c = *(int *)(b + arg0 * 4 + 4);
    return *(int *)(c + 0x10);
}
