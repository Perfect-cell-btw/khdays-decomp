/* Ov008_TickInputUpdate -- if the tick source is early (<2), mark the input object busy
 * (ctx+0x4e8 = 1); then kick its update (Obj_SetField14 with callback Ov008_MissionSelectionSendTick),
 * and return the busy flag. */
extern unsigned short func_01ff8138(void);
extern void Obj_SetField14(int obj, void *cb);
extern void Ov008_MissionSelectionSendTick(void);
extern int  data_ov008_02090f24;   /* title-screen state struct: [1] = input object */

int Ov008_TickInputUpdate(void) {
    if (func_01ff8138() <= 1) {
        *(int *)(data_ov008_02090f24 + 0x4e8) = 1;
    }
    Obj_SetField14(*(int *)((int)&data_ov008_02090f24 + 4), Ov008_MissionSelectionSendTick);
    return *(int *)(data_ov008_02090f24 + 0x4e8);
}
