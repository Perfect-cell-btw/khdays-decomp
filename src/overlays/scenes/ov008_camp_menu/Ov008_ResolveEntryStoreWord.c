/* Finds a layout entry by id and stores its callback (+0x98). */

extern void *Ov008_FindEntryById(void *, void *);
extern void Ov008_StoreWordAt0x98(void *, void *);
void Ov008_ResolveEntryStoreWord(void *arg0, void *arg1, void *arg2)
{
    Ov008_StoreWordAt0x98(Ov008_FindEntryById(arg0, arg1), arg2);
}
