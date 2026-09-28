/* List-scene input tick: reads the button state and touch entry, drives the touch transition flag,
 * and returns the next scene callback. */

#include "nitro/types.h"

typedef void *(*Ov000SceneCallback)(void);

typedef struct Ov000TouchEntry {
    u16 x;
    u16 y;
    u16 active;
    u16 state;
} Ov000TouchEntry;

typedef struct Ov000ListSceneContext {
    s16 selection;
    s16 cursor;
    u16 reserved0004;
    u16 buttonState;
    u8 pad_0008[0x5c];
    int touchTracking;
    u16 inputSource;
    u8 pad_006a[0xa2];
    u8 object010c[0x4c];
    u8 object0158;
    u8 pad_0159[0x4a7f];
    u8 object4bd8;
    u8 pad_4bd9[0x4a8b];
    signed int touchPhase : 8;
    unsigned int touchStateRest : 24;
    u8 pad_9668[2];
    s16 mode;
    u8 pad_966c[0x3b18];
    int touchTransition;
    int inputLocked;
} Ov000ListSceneContext;

extern Ov000ListSceneContext *NNSi_FndGetCurrentRootHeap(void);
extern void func_020362ec(void *input);
extern u16 Mem_ReadU16(const void *input);
extern void Ov000_GetLatestTouchPress(Ov000TouchEntry *touch);
extern int Ov000_PointInBox(const Ov000TouchEntry *touch,
                              const u8 *bounds);
extern void Ov000_UpdateListSelection(const Ov000TouchEntry *touch);
extern void Ov000_ActivateSceneObject(Ov000ListSceneContext *context);
extern void Ov000_QueueResourceTransfers(void);
extern void Ov000_List_StartClose(Ov000ListSceneContext *context);
extern void Ov000_MoveSelectionUp(Ov000ListSceneContext *context);
extern void Ov000_List_CursorNextWrap(Ov000ListSceneContext *context);
extern void Ov000_List_PageUp(Ov000ListSceneContext *context);
extern void Ov000_List_PageDown(Ov000ListSceneContext *context);
extern void Ov000_TickSelectionWidget(void *object);
extern void Ov000_UpdateWidgetLayerDefault(void *object, int value);
extern void *Ov000_FadeTransitionTick(void);

extern const u8 data_ov000_0205a954[4];
extern u16 data_0204c190;

Ov000SceneCallback Ov000_TickListSceneInput(void)
{
    Ov000ListSceneContext *context = NNSi_FndGetCurrentRootHeap();
    Ov000SceneCallback result = 0;
    Ov000TouchEntry touch;

    func_020362ec(&context->inputSource);
    context->buttonState = Mem_ReadU16(&context->inputSource);
    Ov000_GetLatestTouchPress(&touch);

    if (context->touchTransition != 0) {
        if (touch.active == 0) {
            context->touchTransition = 0;
        }
    }

    if (context->touchTransition == 0 && touch.active != 0) {
        if (context->touchPhase == 0) {
            context->touchPhase = 1;

            if (context->touchTracking == 0 &&
                Ov000_PointInBox(&touch, data_ov000_0205a954) != 0) {
                context->touchTracking = 1;
                Ov000_UpdateListSelection(&touch);
            } else if (touch.x >= 0x10 && touch.x < 0xd8 &&
                       touch.y >= 0x10) {
                int threshold = 0x20;
                int row = 0;

                do {
                    if (touch.y < threshold) {
                        context->cursor = context->selection + row;
                        Ov000_ActivateSceneObject(context);
                        Ov000_QueueResourceTransfers();
                        result = Ov000_FadeTransitionTick;
                        break;
                    }
                    row++;
                    threshold += 0x10;
                } while (row < 10);
            }
        } else if (context->touchTracking != 0) {
            Ov000_UpdateListSelection(&touch);
        }
    } else {
        context->touchPhase = 0;
        if (context->touchTracking != 0) {
            context->touchTracking = 0;
        }

        if (context->inputLocked == 0) {
            if ((data_0204c190 & 1) != 0) {
                Ov000_ActivateSceneObject(context);
            } else if ((data_0204c190 & 0x0a) != 0) {
                Ov000_List_StartClose(context);
            } else if ((context->buttonState & 0x40) != 0) {
                Ov000_MoveSelectionUp(context);
            } else if ((context->buttonState & 0x80) != 0) {
                Ov000_List_CursorNextWrap(context);
            } else if ((context->buttonState & 0x20) != 0) {
                Ov000_List_PageUp(context);
            } else if ((context->buttonState & 0x10) != 0) {
                Ov000_List_PageDown(context);
            }

            if (context->mode != 4) {
                result = Ov000_FadeTransitionTick;
            }
        }
    }

    context->inputLocked = 0;
    Ov000_TickSelectionWidget(context->object010c);
    Ov000_UpdateWidgetLayerDefault(&context->object0158, 0);
    Ov000_UpdateWidgetLayerDefault(&context->object4bd8, 0);
    return result;
}
