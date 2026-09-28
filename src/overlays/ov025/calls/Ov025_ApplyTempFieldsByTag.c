extern int Ov025_FindEntryByTag();
extern int Ov025_ApplyTempFieldsAndRestore();

void Ov025_ApplyTempFieldsByTag(int arg0, int arg1, int arg2, int arg3) {
    int r = Ov025_FindEntryByTag(arg0, (unsigned short)arg1);
    Ov025_ApplyTempFieldsAndRestore(arg0, r, arg2, arg3);
}
