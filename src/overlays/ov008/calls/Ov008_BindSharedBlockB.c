extern int Ov008_GetCtxBlock968c(void);
extern void Ov008_SetWord0And20_2(void *, int);
void Ov008_BindSharedBlockB(void *obj)
{
    Ov008_SetWord0And20_2(obj, Ov008_GetCtxBlock968c());
}
