/* Per-frame task of the ov106 scene (skipped while 020208e0 is busy): the +0x8b38 camera mode (+0x8e4c)
 * is chosen (main screen: 0xf while ov002 053840 runs, else 1 at full fade or 0xd; sub screen: 1 while
 * the fade task runs, else 0), the interaction check runs, the camera applies the mode and reports
 * the active screen into +0x8e48 (mirrored to data_0204be04), the fades step and the sub engine's
 * layers follow the main screen. */

#include "nitro/types.h"

extern char *data_ov106_020b8b60;
extern u8 data_0204be04;
extern int func_020208e0(void);
extern int Ov002_World_IsFlagBit2Set(void);
extern int Ov002_Ui_GetState(void);
extern int Ov106_GetSlotWord(int param_1);
extern void Ov106_UpdateInteractPrompt(void);
extern void Obj_SetWord8(void *pCamera, int nMode);
extern char Gfx_ToggleCaptureMode(void *request);
extern void Ov106_StepBrightnessFade(void);
extern void Ov106_ApplyFadeBlend(void);
extern void func_02034138(int arg0);

void Ov106_FrameTask(void)
{
    if (func_020208e0() != 0) {
        return;
    }
    if (*(int *)(data_ov106_020b8b60 + 0x8e48) == 0) {
        if (Ov002_World_IsFlagBit2Set() == 0) {
            if (Ov002_Ui_GetState() == 0x10) {
                *(int *)(data_ov106_020b8b60 + 0x8e4c) = 1;
            } else {
                *(int *)(data_ov106_020b8b60 + 0x8e4c) = 0xd;
            }
        } else {
            *(int *)(data_ov106_020b8b60 + 0x8e4c) = 0xf;
        }
    } else {
        if (Ov106_GetSlotWord(1) == 0) {
            *(int *)(data_ov106_020b8b60 + 0x8e4c) = 0;
        } else {
            *(int *)(data_ov106_020b8b60 + 0x8e4c) = 1;
        }
    }
    Ov106_UpdateInteractPrompt();
    Obj_SetWord8(data_ov106_020b8b60 + 0x8b38, *(int *)(data_ov106_020b8b60 + 0x8e4c));
    *(int *)(data_ov106_020b8b60 + 0x8e48) = Gfx_ToggleCaptureMode(data_ov106_020b8b60 + 0x8b38);
    data_0204be04 = *(int *)(data_ov106_020b8b60 + 0x8e48);
    Ov106_StepBrightnessFade();
    Ov106_ApplyFadeBlend();
    func_02034138(data_0204be04 == 0);
}
