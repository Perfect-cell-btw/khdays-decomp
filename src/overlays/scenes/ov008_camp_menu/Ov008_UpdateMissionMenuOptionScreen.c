/* Processes confirm/cancel input, updates the cursor, redraws the four Mission Menu option labels
 * and returns the next state callback when leaving the screen. */

#include "nitro/types.h"

typedef void (*MissionState)(void);

typedef struct {
    u32 cursorIndex;
    u32 repeatFrames;
} MissionMenuSelectionState;

typedef struct {
    void *resourceBase;
    u32 resourceValue;
    void *resourceData;
} MissionResourceRecord;

typedef struct {
    void *sceneObject;
    u16 inputHeader[13];
    u8 pad_1e[2];
    u32 sessionReady;
    u32 parametersReady;
    u32 singleRowMode;
    u32 menuState;
    u8 menuMetadata[8];
    MissionMenuSelectionState selection;
    u8 rows[0x20];
    MissionResourceRecord resource;
    u8 tail[4];
} MissionMenuContext;

typedef u16 MissionLabel[11];

extern MissionMenuContext *data_ov008_02090fa0;
extern u16 data_0204c190;

extern u32 Ov008_Link_GetMode(void);
extern int Ov008_GetMissionMenuSelection(void);
extern int Ov008_MissionScene_IsFlagSet(void);
extern int Ov008_SetMissionCursorSelection(int selection);
extern void Ov008_MissionScene_SetByte95AC(int cursorIndex);
extern void Ov008_MissionScene_SetByte95AD(int sessionReady);
extern int Ov008_RequestMenuState(u32 state, int animate, int completionValue);
extern void Ov008_UpdateMissionMenuCursor(int entryCount);
extern void Ov008_MissionFillMenuLabels(MissionLabel labels[4]);
extern void Ov008_MissionLeaveSubMenu(void);
extern void Ov008_ResetTextLayers(void);
extern void Ov008_FlushTextLayers(void);
extern void Ov008_ForwardSevenArgs(void *text, int x, int y, int style, int layer, int align,
                                   int visible);
extern void *Ov008_GetVarRecordByIndex(void *resource, int index);
extern void MI_CpuFill8(void *dst, int value, u32 size);
extern void func_020362ec(void *image);
extern void PlaySound(u32 soundId, u32 variant);
extern void func_ov008_0207c498(void);
extern void Ov008_OptionMenuNextStateNoOp(void);

MissionState Ov008_UpdateMissionMenuOptionScreen(void)
{
    int action = 0;
    MissionState nextState = (MissionState)action;
    u8 visibleOptionCount = (u8)Ov008_Link_GetMode();
    u16 buttonBits;
    MissionLabel optionLabels[4];
    u8 optionIndex;

    func_020362ec(data_ov008_02090fa0->inputHeader);
    buttonBits = data_0204c190;
    if ((buttonBits & 1) != 0) {
        action = 1;
    }
    if ((buttonBits & 2) != 0) {
        action = 2;
    }

    if (Ov008_MissionScene_IsFlagSet() != 0) {
        Ov008_UpdateMissionMenuCursor(visibleOptionCount + 1);
        if ((action & 1) != 0) {
            MissionMenuContext *context = data_ov008_02090fa0;
            if (context->selection.cursorIndex == 0) {
                context->sessionReady = 1;
            } else {
                context->sessionReady = 0;
            }
            Ov008_MissionScene_SetByte95AD((u8)data_ov008_02090fa0->sessionReady);
            PlaySound(0, 1);
            nextState = func_ov008_0207c498;
        }
        if ((action & 2) != 0) {
            PlaySound(0, 3);
            Ov008_RequestMenuState(8, 1, 0);
            Ov008_MissionLeaveSubMenu();
            nextState = Ov008_OptionMenuNextStateNoOp;
        }
    }

    Ov008_ResetTextLayers();
    Ov008_ForwardSevenArgs(Ov008_GetVarRecordByIndex(&data_ov008_02090fa0->resource, 0x3c), 0xfa, 2,
                           (u8)1, 1, 1, 1);
    Ov008_ForwardSevenArgs(Ov008_GetVarRecordByIndex(&data_ov008_02090fa0->resource, 0x3d), 0x80,
                           0x60, (u8)1, 1, 3, 1);

    MI_CpuFill8(optionLabels, 0, sizeof(optionLabels));
    Ov008_MissionFillMenuLabels(optionLabels);
    for (optionIndex = 0; optionIndex < 4; optionIndex++) {
        Ov008_ForwardSevenArgs(optionLabels[optionIndex], 0x57, optionIndex * 0x18 + 0x23,
                               (u8)(optionIndex < visibleOptionCount ? 1 : 3), 1, 0, 0);
    }

    Ov008_MissionScene_SetByte95AC((u8)data_ov008_02090fa0->selection.cursorIndex);
    Ov008_SetMissionCursorSelection(Ov008_GetMissionMenuSelection());
    Ov008_ForwardSevenArgs(Ov008_GetVarRecordByIndex(&data_ov008_02090fa0->resource, 0x3e), 0x80,
                           0x98, (u8)1, 1, 3, 0);
    Ov008_ForwardSevenArgs(Ov008_GetVarRecordByIndex(&data_ov008_02090fa0->resource, 0x3f), 10,
                           0xb4, (u8)1, 1, 0, 0);
    Ov008_FlushTextLayers();
    return nextState;
}