/* Ov105_KickIdleHandler -- kick the scene-manager idle handler, ov105. When the manager
 * reports idle (Ov105_EnterMode3Step_c == 0), runs Ov105_WH_ChangeSysState(0xa). */
extern int Ov105_EnterMode3Step_c(void);
extern void Ov105_WH_ChangeSysState(int);
void Ov105_KickIdleHandler(void) {
    if (Ov105_EnterMode3Step_c() == 0) {
        Ov105_WH_ChangeSysState(0xa);
    }
}
