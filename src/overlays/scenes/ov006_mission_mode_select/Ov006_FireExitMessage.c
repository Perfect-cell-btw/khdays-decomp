/* Ov006_FireExitMessage -- fire the Mission Mode-screen exit message 0x200d (dispatch when the input
 * object at ctx+0x4e8 is idle, else forward), run teardown Ov006_FreeSceneBuffers, and drop the
 * context pointer. */
extern void func_020235bc(int msg);
extern void GameState_SetFlag(int msg);
extern void Ov006_FreeSceneBuffers(void);
extern int  data_ov006_020565e4;   /* -> Mission Mode-screen context */

void Ov006_FireExitMessage(void) {
    if (*(int *)(data_ov006_020565e4 + 0x4e8) != 0) {
        GameState_SetFlag(0x200d);
    } else {
        func_020235bc(0x200d);
    }
    Ov006_FreeSceneBuffers();
    data_ov006_020565e4 = 0;
}
