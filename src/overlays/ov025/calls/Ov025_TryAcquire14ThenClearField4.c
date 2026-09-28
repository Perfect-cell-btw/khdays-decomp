extern int Ov025_DrawPageBElement();
extern void Ov025_PageB_UploadSurface154();

void Ov025_TryAcquire14ThenClearField4(int arg0, int arg1, int arg2, int arg3) {
    if (Ov025_DrawPageBElement(0x14, 0, 0, arg3) == 0) return;
    Ov025_PageB_UploadSurface154();
    *(int *)(arg0 + 4) = 0;
}
