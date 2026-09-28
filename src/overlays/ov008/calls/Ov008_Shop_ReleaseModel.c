extern char *data_ov008_02090fac;
extern void ReleaseField74AndCleanup(void *);
void Ov008_Shop_ReleaseModel(void)
{
    ReleaseField74AndCleanup(data_ov008_02090fac + 0xbff0);
}
