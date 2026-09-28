/* Applies the fade tween to both screens' brightness and, when done, picks the next step by mode;
 * ticks the widgets. */

typedef unsigned char u8;
typedef unsigned int u32;
typedef void (*OverlayCallback)(void);

typedef struct {
    u8 pad_0000[0x10c];
    u8 object010c[0x4c];
    u8 object0158[1];
    u8 pad_0159[0x4a7f];
    u8 object4bd8[1];
    u8 pad_4bd9[0x4a91];
    short mode;
    u8 pad_966c[0x3aac];
    u8 tweenBody[0x18];
    u32 tweenFlags01 : 2;
    u32 tweenFinished : 1;
    u32 tweenFlags3_31 : 29;
    u8 pad_d134[0x50];
    int transitionReadyA;
    int transitionReadyB;
} Ov000SceneContext;

extern Ov000SceneContext *NNSi_FndGetCurrentRootHeap(void);
extern void Tween_Sample(void *tween, int *value);
extern void SetMasterBrightnessMain(int brightness);
extern void SetMasterBrightnessSub(int brightness);
extern void Ov000_TickSelectionWidget(void *object);
extern void Ov000_UpdateWidgetLayerDefault(void *object, int value);
extern void Ov000_StartMovieFromMenuRow(void);
extern void Ov000_LeaveTitleForScene(void);
extern void Ov000_TickListSceneInput(void);

OverlayCallback Ov000_FadeTransitionTick(void) {
    Ov000SceneContext *context = NNSi_FndGetCurrentRootHeap();
    OverlayCallback result = 0;
    int brightness;

    Tween_Sample(context->tweenBody, &brightness);
    brightness /= 256;
    if (context->mode == 3) {
        brightness -= 16;
    } else {
        brightness = -brightness;
    }

    SetMasterBrightnessMain(brightness);
    SetMasterBrightnessSub(brightness);

    if (context->tweenFinished) {
        context->transitionReadyA = 1;
        context->transitionReadyB = 1;

        switch (context->mode) {
        case 0:
            result = Ov000_StartMovieFromMenuRow;
            break;
        case 1:
            result = Ov000_LeaveTitleForScene;
            break;
        case 2:
            context->mode = 6;
            result = (OverlayCallback)-2;
            break;
        case 3:
            context->mode = 4;
            result = Ov000_TickListSceneInput;
            break;
        }
    }

    Ov000_TickSelectionWidget(context->object010c);
    Ov000_UpdateWidgetLayerDefault(context->object0158, 0);
    Ov000_UpdateWidgetLayerDefault(context->object4bd8, 0);
    return result;
}
