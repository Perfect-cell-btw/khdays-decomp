/* Sets the menu's step size (0x20 or 0x40) for the mode. */

extern int data_ov025_020b5744;

void Ov025_SetMode95d0(int arg0) {
    switch (arg0) {
    case 0:
        *(int *)(*(int *)((char *)&data_ov025_020b5744 + 4) + 0x95d0) = 0x20;
        break;
    case 1:
        *(int *)(*(int *)((char *)&data_ov025_020b5744 + 4) + 0x95d0) = 0x40;
        break;
    }
}
