/* Looks up the entry in the collision model's name table (case-insensitive). Returns the entry, or
 * NULL when no name matches. */

extern char *FindEntryByNameNoCase(int arg0, void *);

char *CollModel_FindEntry(void *p, void *key)
{
    return FindEntryByNameNoCase(*(int *)*(int **)((char *)p + 4), key);
}
