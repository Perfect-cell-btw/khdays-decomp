extern unsigned short QueryActiveStateOrDelegate(void);
extern int GetEntryField20ByIndex(int arg0);
extern int func_ov022_020ab350(int arg0);
int func_ov022_02088648(void) {
    unsigned short s = QueryActiveStateOrDelegate();
    int e = GetEntryField20ByIndex(s);
    if (e != 0) return func_ov022_020ab350(e);
    return 0;
}
