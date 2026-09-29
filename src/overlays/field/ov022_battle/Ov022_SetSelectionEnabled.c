/* Enables or disables the lock-on selection: updates the caption, the controller, the flags and
 * plays the on/off sound. */

#include "nitro/types.h"
#include "game/engine.h"

typedef struct Ov022ModeContext {
    unsigned int flags0;
    unsigned int flags4;
    char pad_0008[0xe0];
    char subsystemE8[1];
    char pad_00e9[0x147];
    int value230;
} Ov022ModeContext;

extern u8 data_0204be04;
extern Ov022ModeContext *NNSi_FndGetCurrentRootHeap(void);
extern void Ov002_RefreshCaptionWidget(int mode);
extern void Ov022_UpdateSelectionController(void);
extern void func_ov022_020847f0(void);
extern void Ov022_ClearMaskBitsAndReset(void *state, int mask);
extern void Ov022_ClearWords124And128(void *subsystem);

void Ov022_SetSelectionEnabled(int enabled)
{
    Ov022ModeContext *context = NNSi_FndGetCurrentRootHeap();

    GetEntryField20ByIndex(QueryActiveStateOrDelegate());
    if (data_0204be04 == 0) {
        Ov002_RefreshCaptionWidget(enabled);
    }

    if (enabled == 0) {
        goto disabled;
    }
    if (enabled == 0) {
        return;
    }
    Ov022_UpdateSelectionController();
    context->flags0 |= 4;
    context->flags4 |= 2;
    PlaySound(0, 5);
    context->value230 = 0;
    return;

disabled:
    func_ov022_020847f0();
    if (context->value230 == 0 && (context->flags0 & 4) != 0) {
        PlaySound(0, 6);
    }
    context->flags0 &= ~4;
    Ov022_ClearMaskBitsAndReset(&context->flags4, 2);
    Ov022_ClearWords124And128(context->subsystemE8);
}
