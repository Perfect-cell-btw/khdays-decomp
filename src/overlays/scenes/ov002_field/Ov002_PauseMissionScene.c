typedef unsigned char u8;

extern char *data_ov002_0207fa00;
/* Boot mode flags; bit 2 marks a run that came up without the front end. */
extern u8 data_0204c240;

/* Non-zero while the scene is already suspended for something else. */
extern int Ov002_GetRootField8b68Alt(void);
extern int GameState_IsFlagSet(int nCue);
extern void Obj_SetField14(int nHandle, void (*pfnStep)(void));
extern void Callbacks_SetByte(int nValue);
extern void func_02020878(int nValue);
extern void Ov002_SessionTick(void);

/* Put the mission scene into its paused state.
 *
 * A scene that is already stopping or stopped (either of the low two bits of
 * the state word) is left alone.  Otherwise the pause cue is offered first --
 * only for a run that came up through the front end, and only while nothing
 * else holds the scene -- and taking it hands the scene over to the pause
 * step.  Whether or not the cue was taken, the scene is marked paused and both
 * the sound and the input side are told to go quiet.
 */
void Ov002_PauseMissionScene(void)
{
    char *pCtx;

    pCtx = data_ov002_0207fa00;
    if ((*(int *)(pCtx + 0x8b64) & 3) != 0) {
        return;
    }

    if ((data_0204c240 & 4) == 0 && Ov002_GetRootField8b68Alt() != 0
        && GameState_IsFlagSet(0x20ef) != 0) {
        *(u8 *)(pCtx + 0x8b68) = 0x10;
        Obj_SetField14(*(int *)pCtx, Ov002_SessionTick);
    }

    if (Ov002_GetRootField8b68Alt() != 0) {
        return;
    }

    *(int *)(pCtx + 0x8b64) |= 1;
    *(u8 *)(pCtx + 0x8b68) |= 0x10;
    if ((data_0204c240 & 4) != 0) {
        Callbacks_SetByte(0);
    }
    func_02020878(0);
}
