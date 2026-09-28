extern int Ov025_GetPageB();

void Ov025_PageB_ClearHold(int arg0) {
    *(int *)(Ov025_GetPageB(arg0) + 0x1f0) = 0;
}
