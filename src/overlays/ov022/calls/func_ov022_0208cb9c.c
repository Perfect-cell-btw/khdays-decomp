extern int QueryActiveStateOrDelegate(void);
extern int Ov022_GetEntryField66(unsigned int arg0);
extern void Ov022_CopyMtxClearFlagThenNotify_2(int arg0);

void func_ov022_0208cb9c(int arg0, int arg1, int arg2, int arg3) {
    int e = *(int *)(arg0 + *(int *)(arg0 + 0xc) * 4 + 0x18);
    unsigned char c;
    if (*(char *)(e + 0x110) != Ov022_GetEntryField66(QueryActiveStateOrDelegate())) return;
    if (Ov022_GetEntryField66(QueryActiveStateOrDelegate()) == -1) return;
    c = *(unsigned char *)(e + 0x118);
    if (c == 4 || c == 0) return;
    Ov022_CopyMtxClearFlagThenNotify_2(arg0);
}
