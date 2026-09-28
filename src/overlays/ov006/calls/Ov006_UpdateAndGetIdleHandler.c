/* Ov006_UpdateAndGetIdleHandler -- if the shared flag is set run ReleaseServiceInstance, advance Mission Mode input
 * (Ov006_TickCardTransferScene), then return the idle handler Ov006_IdleStateNoOp when ctx+0x49c is
 * clear, else 0. */
extern int  Session_Exists(void);   /* shared-flag test */
extern void ReleaseServiceInstance(void);
extern void Ov006_TickCardTransferScene(void);
extern void Ov006_IdleStateNoOp(void);
extern int  data_ov006_020565e4;   /* -> Mission Mode-screen context */

int Ov006_UpdateAndGetIdleHandler(void) {
    int result = 0;
    if (Session_Exists() != 0) {
        ReleaseServiceInstance();
    }
    Ov006_TickCardTransferScene();
    if (*(int *)(data_ov006_020565e4 + 0x49c) == 0) {
        result = (int)Ov006_IdleStateNoOp;
    }
    return result;
}
