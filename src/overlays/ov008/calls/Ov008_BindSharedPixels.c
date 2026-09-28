extern int Ov008_GetCtxBlock968c(void);
void Ov008_BindSharedPixels(int *obj)
{
    obj[0] = Ov008_GetCtxBlock968c();
    obj[8] = obj[0];
}
