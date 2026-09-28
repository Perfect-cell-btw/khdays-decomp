/* Chain Ov005_FindEntryById(param_1, param_2) into Ov005_StoreWordAt0x98 with param_3. */
extern int Ov005_FindEntryById(int a, int b);
extern void Ov005_StoreWordAt0x98(int a, int b);
void Ov005_ResolveEntryStoreWord(int param_1, int param_2, int param_3) {
    Ov005_StoreWordAt0x98(Ov005_FindEntryById(param_1, param_2), param_3);
}
