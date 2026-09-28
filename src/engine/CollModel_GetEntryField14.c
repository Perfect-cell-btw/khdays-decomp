/* Field +0x14 of the collision model's entry. */

extern int *CollModel_FindEntry(void);

int CollModel_GetEntryField14(void) {
    return CollModel_FindEntry()[5];
}
