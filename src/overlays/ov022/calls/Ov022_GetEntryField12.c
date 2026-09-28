extern int GetEntryField20ByIndex();

int Ov022_GetEntryField12(int arg0) {
    int e = GetEntryField20ByIndex(arg0);
    return e == 0 ? 0 : *(unsigned short *)(e + 0x12);
}
