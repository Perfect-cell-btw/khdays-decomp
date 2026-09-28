/* Sets bit 2 of the menu state. */

extern int data_ov025_020b5740;

void Ov025_SetMenuFlag4(void) {
    int p = *(int *)&data_ov025_020b5740;
    *(int *)p |= 4;
}
