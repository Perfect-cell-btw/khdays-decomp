/* Stores the menu configuration value, sets the state to 7, blits the configuration region and
 * enables both screen halves. */

extern void Ov025_SetCtxField95cc();
extern void Ov025_BlitConfigRegion();
extern void Ov025_EnableBothHalves();
extern int data_ov025_020b5744;

void Ov025_SetGlobalConfigAndInit(int arg0) {
    *(int *)(((int *)&data_ov025_020b5744)[1] + 0x95c8) = arg0;
    Ov025_SetCtxField95cc(7);
    Ov025_BlitConfigRegion(-0x10, 100);
    Ov025_EnableBothHalves(0);
}
