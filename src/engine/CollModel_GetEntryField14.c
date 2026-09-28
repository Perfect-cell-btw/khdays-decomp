/* Field +0x14 of the collision model's entry. */

extern int *CollModel_FindEntry(void *);

int CollModel_GetEntryField14(void *arg0) {
    return CollModel_FindEntry(arg0)[5];
}
