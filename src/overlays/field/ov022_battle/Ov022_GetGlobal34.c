/* Returns the battle context's word at +0x34. */

extern int data_ov022_020b2e60;
int Ov022_GetGlobal34(void) { return *(int *)(data_ov022_020b2e60 + 0x34); }
