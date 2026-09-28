extern int *Ov302_CreateEncounterRecord(int entry, int body);
extern void NNS_FndAppendListObject(int list, int entry);

// Walk the variable-length record list (count-prefixed, each record self-sized).
// For every record the predicate accepts, build a node and append it to this+0x18,
// counting the ones whose slot (entry[4]) is still free. Returns that count.
int Ov302_ParseRecordListAppendMatches(int this, unsigned short *p, int arg, void *predicate)
{
    int i;
    unsigned short matched = 0;
    int count = *p++;
    i = 0;
    if (count > 0) {
        do {
            if (((int (*)(unsigned short *, int))predicate)(p, arg) != 0) {
                int *entry = Ov302_CreateEncounterRecord((int)p, (int)(p + 0x18));
                NNS_FndAppendListObject(this + 0x18, (int)entry);
                if (entry[4] == 0) {
                    matched++;
                }
            }
            i++;
            p = (unsigned short *)((int)p + *p);
        } while (i < count);
    }
    return matched;
}
