/* Opens sub-object `id`: resets its counter at +0x1e8, records the id, arms it (+0x1f0 = 1),
 * pushes the per-id parameter word into the sub-block at +0x200, runs the fallback when
 * Ov025_IsEntryBusyOrInactive reports nothing pending, and finally kicks Ov025_PlaceTutorialSurfaces. */
extern char *Ov025_GetPageB(int id);
extern void Ov025_FindChunkById(char *p, unsigned short v);
extern int Ov025_IsEntryBusyOrInactive(void);
extern void Ov025_InitOverlayFade(void);
extern void Ov025_PlaceTutorialSurfaces(void);
extern int data_ov025_020b5588[];

void Ov025_OpenSubObject(int id) {
    char *o = Ov025_GetPageB(id);
    *(int *)(o + 0x1e8) = 0;
    *(int *)o = id;
    *(int *)(o + 0x1f0) = 1;
    Ov025_FindChunkById(o + 0x200, (unsigned short)data_ov025_020b5588[id]);
    if (Ov025_IsEntryBusyOrInactive() == 0) {
        Ov025_InitOverlayFade();
    }
    Ov025_PlaceTutorialSurfaces();
}
