/* Ov006_TickInputUpdate -- if the tick source is early (<2), mark the input object busy
 * (ctx+0x4e8 = 1); then kick its update (Obj_SetField14 with callback Ov006_MissionSelectionSendTick),
 * and return the busy flag. */
extern unsigned short func_01ff8138(void);
extern void Obj_SetField14(int obj, void *cb);
extern void Ov006_MissionSelectionSendTick(void);
extern int  data_ov006_020565e4;   /* Mission Mode-screen state struct: [1] = input object */

int Ov006_TickInputUpdate(void) {
    if (func_01ff8138() <= 1) {
        *(int *)(data_ov006_020565e4 + 0x4e8) = 1;
    }
    Obj_SetField14(*(int *)((int)&data_ov006_020565e4 + 4), Ov006_MissionSelectionSendTick);
    return *(int *)(data_ov006_020565e4 + 0x4e8);
}
