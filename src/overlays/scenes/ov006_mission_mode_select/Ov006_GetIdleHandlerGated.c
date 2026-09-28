/* Ov006_GetIdleHandlerGated -- return the Mission Mode update handler Ov006_UpdateAndGetIdleHandler when the input
 * object is idle (ctx+0x4e8 == 0) and Ov006_CanAdvancePastIntro allows it, else 0. */
extern int  Ov006_CanAdvancePastIntro(void);
extern void Ov006_UpdateAndGetIdleHandler(void);
extern int  data_ov006_020565e4;   /* -> Mission Mode-screen context */

int Ov006_GetIdleHandlerGated(void) {
    if (*(int *)(data_ov006_020565e4 + 0x4e8) == 0 && Ov006_CanAdvancePastIntro() != 0) {
        return (int)Ov006_UpdateAndGetIdleHandler;
    }
    return 0;
}
