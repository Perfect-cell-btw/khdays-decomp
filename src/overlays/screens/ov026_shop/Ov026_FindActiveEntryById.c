/* Returns the first active entry (non-zero word at +0xc) with the given id, or the end of the entry
 * array when none matches. */

struct Entry {
    unsigned short id;
    short pad;
    int field4;
    int field8;
    int fieldC;
};

struct Obj {
    char pad0[0x14];
    struct Entry *entries;
    char pad18[0x38 - 0x18];
    int count;
};

struct Entry *Ov026_FindActiveEntryById(struct Obj *obj, int id) {
    int i;
    for (i = 0; i < obj->count; i++) {
        if (obj->entries[i].fieldC != 0) {
            if (id == obj->entries[i].id) {
                break;
            }
        }
    }
    return &obj->entries[i];
}
