extern int Ov008_DrawPageBElement(int arg0, int arg1, int arg2);
extern void Ov008_PageB_UploadSurface154(void);

void Ov008_TryAcquire14ThenClearField4(void *object)
{
    if (Ov008_DrawPageBElement(0x14, 0, 0) != 0) {
        Ov008_PageB_UploadSurface154();
        *(int *)((char *)object + 4) = 0;
    }
}
