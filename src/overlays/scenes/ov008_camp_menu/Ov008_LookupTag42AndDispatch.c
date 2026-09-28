extern int Ov008_GetCtxBlock954c(void);
extern int Ov008_FindEntryByTag(int, int);
extern void Ov008_TagTracker_InvokeCallback(int, int);
void Ov008_LookupTag42AndDispatch(void)
{
    int base = Ov008_GetCtxBlock954c();
    Ov008_TagTracker_InvokeCallback(base, Ov008_FindEntryByTag(base, 0x42));
}
