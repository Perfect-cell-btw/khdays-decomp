extern int *CollModel_FindEntry(void);

int CollModel_GetEntryField14(void) {
    return CollModel_FindEntry()[5];
}
