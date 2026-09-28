/* Returns the address of the setup argument block's object + 0xe0. */

extern int data_ov022_020b2e78;
int Ov022_GetGlobalPlusE0(void) { return ((int *)&data_ov022_020b2e78)[1] + 0xe0; }
