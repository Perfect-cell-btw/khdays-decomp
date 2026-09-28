/* Looks up the entry in the collision model's name table (case-insensitive). Returns the entry, or
 * NULL when no name matches. */

extern char *FindEntryByNameNoCase(int arg0);

char *CollModel_FindEntry(void *p)
{
    return FindEntryByNameNoCase(*(int *)*(int **)((char *)p + 4));
}
