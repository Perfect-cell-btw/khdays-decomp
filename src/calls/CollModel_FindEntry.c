extern void FindEntryByNameNoCase(int arg0);

void CollModel_FindEntry(void *p)
{
    FindEntryByNameNoCase(*(int *)*(int **)((char *)p + 4));
}
