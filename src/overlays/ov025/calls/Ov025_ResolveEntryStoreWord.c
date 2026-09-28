extern int Ov025_FindEntryById();
extern void Ov025_StoreWordAt0x98();

void Ov025_ResolveEntryStoreWord(int arg0, int arg1, int arg2) {
    Ov025_StoreWordAt0x98(Ov025_FindEntryById(arg0, arg1), arg2);
}
