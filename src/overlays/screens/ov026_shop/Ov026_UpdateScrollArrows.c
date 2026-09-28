extern char *data_ov026_02091368;
extern int Ov026_FindEntryById(void *p, int id);
extern void Ov026_SetEntrySlotsVisible(void *p, int cell, int on);

/* Greys out the two scroll arrows according to whether the list can move up or down. */
void Ov026_UpdateScrollArrows(void) {
    char *st = *(char **)&data_ov026_02091368;
    char *view = st + 0xc3c4;
    char *arrows = st + 0x2ab0;
    Ov026_SetEntrySlotsVisible(arrows, Ov026_FindEntryById(arrows, 4), *(int *)(view + 4) != 0);
    Ov026_SetEntrySlotsVisible(arrows, Ov026_FindEntryById(arrows, 5),
                        (unsigned int)(*(int *)(view + 4) + 8) < (unsigned int)*(int *)(view + 8));
}
