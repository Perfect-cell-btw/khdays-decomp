extern int GetEntryField20ByIndex();
int func_ov022_0208840c(int arg0) {
    int e = GetEntryField20ByIndex(arg0);
    return e == 0 ? -1 : *(char *)(e + 0x4bc);
}
