/* Ov008_EnterMode1 -- if menu busy/lock bit 4 of *(u16*)(obj+0x5c6) is set, return; otherwise
 * enter menu mode 1: set mode (Ov008_PrimeSubSceneFromCursor), enable two sub-widgets
 * (Ov008_SetCtxObject9630/02051010), set the active slot (Ov008_SetTargetSlot(1,-1)), fire the UI
 * event (PlaySound(0,1)) and notify (Ov008_SetBusyFlag). ov008; 02059a54 family sibling. */
extern int  Ov008_PrimeSubSceneFromCursor(int mode);
extern void Ov008_SetCtxObject9630(int a);
extern void Ov008_SetCtxObject9634(int a);
extern void Ov008_SetTargetSlot(int a, int b);
extern void PlaySound(int a, int b);
extern void Ov008_SetBusyFlag(int a);
extern char *data_ov008_02090f1c;   /* -> menu/status object */

void Ov008_EnterMode1(void) {
    if ((((unsigned)*(unsigned short *)(data_ov008_02090f1c + 0x5c6) << 0x1b) >> 0x1f) != 0) {
        return;
    }
    Ov008_PrimeSubSceneFromCursor(1);
    Ov008_SetCtxObject9630(1);
    Ov008_SetCtxObject9634(1);
    Ov008_SetTargetSlot(1, -1);
    PlaySound(0, 1);
    Ov008_SetBusyFlag(0);
}
