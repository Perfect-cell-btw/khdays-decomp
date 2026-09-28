extern char *data_ov008_02090fac;
extern int Ov008_FindEntryById(void *p, int id);
extern void Ov008_SetEntrySlotsVisible(void *p, int cell, int on);

/* Greys out the two scroll arrows according to whether the list can move up or down. */
void Ov008_UpdateScrollArrows_3(void) {
    char *st = *(char **)&data_ov008_02090fac;
    char *view = st + 0xc3c4;
    char *arrows = st + 0x2ab0;
    Ov008_SetEntrySlotsVisible(arrows, Ov008_FindEntryById(arrows, 4), *(int *)(view + 4) != 0);
    Ov008_SetEntrySlotsVisible(arrows, Ov008_FindEntryById(arrows, 5),
                        (unsigned int)(*(int *)(view + 4) + 8) < (unsigned int)*(int *)(view + 8));
}
