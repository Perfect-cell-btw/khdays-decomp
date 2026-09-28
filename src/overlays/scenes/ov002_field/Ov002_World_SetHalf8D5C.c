/* Stores the root context's halfword at +0x8d5c. */

extern int data_ov002_0207fa00;

void Ov002_World_SetHalf8D5C(int arg0) {
    *(short *)(*(int *)&data_ov002_0207fa00 + 0x8d5c) = arg0;
}
