/* Steps the cursor tween and, when it ends, either returns to the fade state or builds the preset
 * rows and starts the scale tweens; updates the cursor with the value. */

#include "nitro/types.h"
#include "game/engine.h"

typedef struct Ov022RootFlags {
    u32 unknown0 : 2;
    u32 finished : 1;
    u32 unknown3 : 29;
} Ov022RootFlags;

typedef struct Ov022RootContext {
    char padding000[0xc0];
    signed char state;
    signed char substate1;
    signed char substate2;
    signed char substate3;
    char padding0c4[0x11c];
    int tweenCursor[6];
    Ov022RootFlags flags;
} Ov022RootContext;

extern Ov022RootContext *NNSi_FndGetCurrentRootHeap(void);
extern void Tween_Sample(void *tween, int *value);
extern void Ov022_BuildPresetRows(void);
extern void func_ov022_02086d60(int value);
extern int Ov022_AdvanceFadeStateThenNextStep(void);
extern int Ov022_StepScaleTweens(void);
extern int data_0204be04;

int Ov022_StepCursorTween(void)
{
    Ov022RootContext *context = NNSi_FndGetCurrentRootHeap();
    int value;
    int result = 0;

    if (*(unsigned char *)&data_0204be04 != 0) {
        return 0;
    }

    Tween_Sample(context->tweenCursor, &value);
    if (context->flags.finished) {
        if (context->substate3 == 0) {
            context->state = 0;
            result = (int)Ov022_AdvanceFadeStateThenNextStep;
        } else {
            Ov022_BuildPresetRows();
            PlaySoundChecked(0, 0x27);
            value = 0;
            result = (int)Ov022_StepScaleTweens;
        }
    }
    func_ov022_02086d60(value);
    return result;
}
