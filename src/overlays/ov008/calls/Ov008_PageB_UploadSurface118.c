extern char *Ov008_GetPageB(void);
extern int data_ov008_02090f20;
extern void EnqueueObjGfxCommand(void *);
void Ov008_PageB_UploadSurface118(void)
{
    char *obj = Ov008_GetPageB();
    if (data_ov008_02090f20 != 0) {
        EnqueueObjGfxCommand(obj + 0x118);
    }
}
