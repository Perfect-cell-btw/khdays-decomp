/*
 * Ov002_LookupValueByKey - look up a mapped value for a key among the active objects (ARM).
 *
 * Iterates the list's objects (fetched one at a time by Ov002_MulTagAtField4ePlusField54). For the first active
 * object (flag bit 0 at +0x12 set) whose key byte at +0x1b9 equals `key`, returns its mapped value
 * byte at +0x1ba; returns -1 if none match. The object count is re-read each iteration because the
 * per-object fetch call may change it.
 */
typedef struct {
    char _0[0x50];
    unsigned short objCount;    /* +0x50 */
} Ov002List;

extern int Ov002_MulTagAtField4ePlusField54(int list, int index);

int Ov002_LookupValueByKey(Ov002List *list, int key)
{
    int i;
    for (i = 0; i < list->objCount; i++) {
        int entry = Ov002_MulTagAtField4ePlusField54((int)list, i);
        if ((*(unsigned short *)(entry + 0x12) & 1) &&
            *(signed char *)(entry + 0x1b9) == key) {
            return *(signed char *)(entry + 0x1ba);
        }
    }
    return -1;
}
