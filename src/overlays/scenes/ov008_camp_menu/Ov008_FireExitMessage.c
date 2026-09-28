/* Ov008_FireExitMessage -- fire the title-screen exit message 0x200d (dispatch when the input
 * object at ctx+0x4e8 is idle, else forward), run teardown Ov008_FreeSceneBuffers, and drop the
 * context pointer. */
extern void func_020235bc(int msg);
extern void GameState_SetFlag(int msg);
extern void Ov008_FreeSceneBuffers(void);
extern int  data_ov008_02090f24;   /* -> title-screen context */

void Ov008_FireExitMessage(void) {
    if (*(int *)(data_ov008_02090f24 + 0x4e8) != 0) {
        GameState_SetFlag(0x200d);
    } else {
        func_020235bc(0x200d);
    }
    Ov008_FreeSceneBuffers();
    data_ov008_02090f24 = 0;
}
