/* Stores the menu state's position (+0x9638, +0x963a). */

extern int data_ov025_020b5744;

void Ov025_SetCtxFields9638And963a(int arg0, int arg1) {
    *(short *)(*(int *)((char *)&data_ov025_020b5744 + 4) + 0x9638) = arg0;
    *(short *)(*(int *)((char *)&data_ov025_020b5744 + 4) + 0x963a) = arg1;
}
