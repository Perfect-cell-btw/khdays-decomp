/* Record index -> pointer: the entity manager's table for a free actor, else the actor's own table
 * (+0xac); NULL for 0xff. */

extern void *EntityMgr_GetRecord(int index);

void *Actor_GetRecord(unsigned char *ptr, int index) {
    if (*(unsigned char **)(ptr + 4) == ptr + 0x10) {
        if (index == 0xff) {
            return 0;
        }
        return EntityMgr_GetRecord(index);
    }

    ptr = *(unsigned char **)ptr;
    if (index == 0xff) {
        return 0;
    }

    return *(unsigned char **)(ptr + 0xac) + index * 0x14;
}
