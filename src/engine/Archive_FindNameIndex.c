/*
 * Archive_FindNameIndex - resolve a name string to its member index inside an archive's name table.
 *
 * Member 0 of the archive (fetched via Archive_GetMember(desc, 0, 0)) is a name/tag table laid out as
 *   u16 count;             // number of named entries
 *   u16 offsets[count];    // byte offset of each entry's name string, relative to the table base
 *   ...string data...      // NUL-terminated names
 * Each candidate name lives at (table_base + offsets[i]); strcmp is a byte-wise strcmp that
 * returns 0 on equality. The first name matching `name` yields its index; -1 means "not found".
 * The caller (Game_PushObjectSlot / Game_PushObjectSlot) feeds the returned index straight into
 * Archive_GetMember(desc, 1, index) to fetch the real member.
 *
 * THUMB. Matching note: the offset-table read must stay a re-add of the table base, not an advancing
 * pointer. Writing the base as a `char *` and spelling the index as `base + i*2 + 2` keeps `i` the
 * loop counter and lets mwcc strength-reduce a separate byte offset (r5, `+= 2`) whose init is placed
 * in the loop preheader (`adds r5,r6,#0`, after the count guard) and re-added to the base each
 * iteration (`adds r1,r4,r5`). A cached `int count = tbl->count` with a struct subscript
 * `tbl->offsets[i]` instead folds the whole thing into one advancing halfword pointer plus a
 * duplicated base copy (56 bytes vs the target's 58).
 */

extern void *Archive_GetMember(int desc, int type, int idx);
extern int   strcmp(const char *a, const char *b);

int Archive_FindNameIndex(int desc, const char *name)
{
    char *base = (char *)Archive_GetMember(desc, 0, 0);
    int count = *(unsigned short *)base;
    int i;

    for (i = 0; i < count; i++) {
        if (strcmp(name, base + *(unsigned short *)(base + i * 2 + 2)) == 0) {
            return i;
        }
    }
    return -1;
}
