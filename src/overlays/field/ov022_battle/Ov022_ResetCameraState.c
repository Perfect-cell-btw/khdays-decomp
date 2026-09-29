/* Initialises the battle state: resets the camera and selector fields, registers the network
 * handlers, loads the marker panels and ov029, sets up each player's state and the header limits;
 * returns the scene dispatch step. */

#include "game/engine.h"

typedef struct Ov022InitHeader {
    short values[13];
} Ov022InitHeader;

typedef struct Ov022CameraState {
    int enabled;
    char padding004[0x30];
    unsigned char stageId;
    char padding035[3];
    int activeSelector;
    unsigned char flags;
    signed char sentinel;
    char padding03e[2];
    int holdTicks;
    int overlayId;
    unsigned short savedSelectorA;
    unsigned short savedSelectorB;
    Ov022InitHeader header;
    char padding066[2];
    char outputEye[0x3c];
    char focusApproach[0x3c];
    unsigned char outputEyeState;
    unsigned char focusApproachState;
} Ov022CameraState;

typedef int (*Ov022SceneCallback)(void);
typedef unsigned int FSOverlayID;

extern unsigned int OVERLAY_29_ID;
#define FS_OVERLAY_ID_ov029 ((FSOverlayID)(unsigned int)&OVERLAY_29_ID)

extern Ov022CameraState *NNSi_FndGetCurrentRootHeap(void);
extern char data_ov022_020b2e78;
extern unsigned char data_02042a1d;
extern void func_ov022_020b145c(void);
extern void Ov022_RegisterHandlerC(void);
extern void Ov022_RegisterHandler10(void);
extern void Ov022_LoadMarkerPanel(void *object, int index);
extern void Ov022_FillSelectorStates(unsigned int *input);
extern int Ov022_TickSceneDispatch(void);

Ov022SceneCallback Ov022_ResetCameraState(unsigned int *input)
{
    Ov022CameraState *state = NNSi_FndGetCurrentRootHeap();
    int overlayId;

    *(Ov022CameraState **)((char *)&data_ov022_020b2e78 + 4) = state;
    state->enabled = 1;
    state->stageId = 0;
    state->activeSelector = -1;
    state->flags &= ~4;
    state->flags &= ~2;
    state->flags &= ~8;
    state->savedSelectorA = 0;
    state->savedSelectorB = 0;
    state->sentinel = -1;
    state->holdTicks = 0;
    state->outputEyeState = 0;
    state->focusApproachState = 0;
    state->stageId = data_02042a1d;
    func_ov022_020b145c();
    Ov022_RegisterHandlerC();
    Ov022_RegisterHandler10();
    Ov022_LoadMarkerPanel(state->outputEye, 0);
    Ov022_LoadMarkerPanel(state->focusApproach, 1);
    overlayId = FS_OVERLAY_ID_ov029;
    LoadOverlaySync(0, overlayId);
    state->overlayId = overlayId;
    Ov022_FillSelectorStates(input);
    Header_InitWithLimits(state->header.values, 0);
    return Ov022_TickSceneDispatch;
}
