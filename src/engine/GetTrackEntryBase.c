/* Returns the address of the indexed track entry header of the entity manager. */

extern char *gEntityMgr;

void *GetTrackEntryBase(int idx)
{
    return (void *)(gEntityMgr + 4 + (idx << 3));
}
