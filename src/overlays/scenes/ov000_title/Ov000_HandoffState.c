/* Ov000_HandoffState -- Scene 1 (boot/logo) hand-off state, ov000.
 * A 3-phase sub-state machine (phase counter = u16 at heap+0x4c50) that waits for
 * the next scene to become ready before advancing:
 *   phase 0: reset the retry/attempt counters (heap+0x4c52/+0x4c53), run
 *            Ov000_BeginCardTransfer, force both screens dark, phase++.
 *   phase 1: poll Ov000_PollSaveLoad and act on its result (retry bookkeeping;
 *            on result 3 re-instantiate the scene class @data_ov000_0205a9c0; on
 *            result 0 probe GameState_GetField and set a flag). Once the attempt counter
 *            (heap+0x4c52) reaches 3, phase++.
 *   phase 2: advance to Ov000_MenuFadeInState.
 * Any other phase (and the fall-through of 0/1) returns 0 (stay). 
 *
 * Both calls to Ov000_BeginCardTransfer pass an argument: the extern here said `(void)` and the
 * definition takes one (tools/audit_extern_sig.py names it). In phase 0 the argument is the same
 * 0 the two byte fields are cleared with -- one constant doing double duty, which is why it looks
 * argument-free -- and in phase 1 it is the freshly incremented attempt counter, the very value
 * the `< 3` test compares. Binding that increment to a local is what makes the ROM's
 * `and r0,r2,#0xff` serve both the compare and the call.
 */

typedef void *StateFn;

extern void *NNSi_FndGetCurrentRootHeap(void);
extern void  Ov000_BeginCardTransfer(int a);
extern int   Ov000_PollSaveLoad(void);
extern int   GameState_GetField(int, int);
extern void  InstantiateClass(void *classDesc, int arg);
extern void  SetMasterBrightnessMain(int brightness);
extern void  SetMasterBrightnessSub(int brightness);
extern char  data_ov000_0205a9c0[];
extern void  Ov000_MenuFadeInState(void);

StateFn Ov000_HandoffState(void) {
    char *h = (char *)NNSi_FndGetCurrentRootHeap();
    unsigned short phase = *(unsigned short *)(h + 0x4c50);
    switch (phase) {
    case 0:
        *(unsigned char *)(h + 0x4c53) = 0;
        *(unsigned char *)(h + 0x4c52) = 0;
        Ov000_BeginCardTransfer(0);
        SetMasterBrightnessMain(0x10);
        SetMasterBrightnessSub(0x10);
        (*(unsigned short *)(h + 0x4c50))++;
        break;
    case 1:
        switch (Ov000_PollSaveLoad()) {
        case 3:
            InstantiateClass(data_ov000_0205a9c0, 2);
            break;
        case 0:
            if (GameState_GetField(0x44e, 3) == 6) {
                *(int *)(h + 0x4c54) |= 1;
            }
            /* fallthrough */
        case 4:
            (*(unsigned char *)(h + 0x4c53))++;
            /* fallthrough */
        case 2:
            {
                unsigned char n = ++*(unsigned char *)(h + 0x4c52);
                if (n < 3) {
                    Ov000_BeginCardTransfer(n);
                }
            }
            break;
        }
        if (*(unsigned char *)(h + 0x4c52) >= 3) {
            (*(unsigned short *)(h + 0x4c50))++;
        }
        break;
    case 2:
        return (StateFn)Ov000_MenuFadeInState;
    }
    return 0;
}
