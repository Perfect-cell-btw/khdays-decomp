extern int Obj_IsIdFree(int h);
extern void Ov000_StartNewGameMode(void);
extern void Ov000_ModeSelect_InitObjects(void);
extern void Ov000_SetupLogoTileSurfaces(void);
extern long long OS_GetTick(void);
extern void Ov000_DispatchIndexedCallback(void);
extern char *data_ov000_0205ac28;

/* Waits for the pending load; once it lands, builds the three menu layers, records the 64-bit
 * timestamp and hands over to the menu tick. */
void *Ov000_WaitLoadThenBuildMenu(void) {
    void *next = 0;
    if (Obj_IsIdFree(*(int *)(data_ov000_0205ac28 + 0x4000 + 0xb00)) != 0) {
        long long stamp;
        Ov000_StartNewGameMode();
        Ov000_ModeSelect_InitObjects();
        Ov000_SetupLogoTileSurfaces();
        stamp = OS_GetTick();
        next = (void *)&Ov000_DispatchIndexedCallback;
        *(long long *)(data_ov000_0205ac28 + 0x14) = stamp;
    }
    return next;
}
