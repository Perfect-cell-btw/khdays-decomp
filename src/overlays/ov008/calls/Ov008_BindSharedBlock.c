extern int Ov008_GetCtxBlock968c(void);
extern void Ov008_SetWord0And20(void *, int);
void Ov008_BindSharedBlock(void *obj)
{
    Ov008_SetWord0And20(obj, Ov008_GetCtxBlock968c());
}
