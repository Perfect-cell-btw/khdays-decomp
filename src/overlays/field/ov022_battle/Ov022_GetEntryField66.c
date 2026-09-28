extern int GetEntryField20ByIndex();
int Ov022_GetEntryField66(int arg0) {
    int e = GetEntryField20ByIndex(arg0);
    return e == 0 ? -1 : *(short *)(e + 0x66);
}
