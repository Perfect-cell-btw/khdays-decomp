extern int GetEntryField20ByIndex(int arg0);
extern int data_02041dc8;
int func_ov022_020881f8(int arg0) {
    int e = GetEntryField20ByIndex(arg0);
    if (e == 0) return (int)&data_02041dc8;
    return e + 0x48c;
}
