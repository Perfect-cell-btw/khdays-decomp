/* Stores world flag byte idx (+0x8c99). */

extern int data_ov002_0207fa00;

void Ov002_World_SetFlagByte(int arg0, int arg1) {
    *(char *)(*(int *)&data_ov002_0207fa00 + arg0 + 0x8c99) = arg1;
}
