/* Ov000_UpdateLoadState -- Scene 1: tick one load-phase slot (Ghidra: Ov000_UpdateLoadState).
 * State machine on context->loadState (+0x4afb): state 0 arms the slot (current = base,
 * stride 0x20 at +0x4b20), calls the phase starter and advances to state 1; state 1 polls
 * Ov000_PollSaveCheck -- 3 = save-check special path (state 2, mode 3, control word at
 * +0x6a48 = (x & 0xffff0000) | 1, both counters cleared), >= 0 = record the result
 * (Ov000_RecordLoadResult(slot, result)) and optionally set bit0 of +0x6a50 when
 * GameState field 0x44e reads 6. Returns the (possibly updated) state byte.
 * MATCH NOTES: Ov000_MarkSceneReady really takes the slot argument (its own file matched
 * as void(void) because a dropped trailing arg does not change the callee's bytes), and
 * Ov000_RecordLoadResult takes (slot, result) -- result homed in r1 produces the ROM's
 * mov r1,r0 after the poll call. Return type is u8 (caller Ov000_TickLoadScene). */
#include "nitro/types.h"

typedef struct Ov000PageSlot {
    int base;
    int current;
    u8  pad_0008[0x18];
} Ov000PageSlot;

typedef struct Ov000LoadContext {
    u8 pad_0000[0x4adc];
    int field_4adc;
    u8 pad_4ae0[0x4afb - 0x4ae0];
    u8 loadState;
    u8 pad_4afc[0x4b20 - 0x4afc];
    Ov000PageSlot slots[1];
} Ov000LoadContext;

typedef struct Ov000FadeBlock {
    u8 pad_0000[0x6a48];
    u32 controlWord;
    u8 pad_6a4c[4];
    u32 resultWord;
    u32 requestWord;
    u8 pad_6a58[4];
    u32 counterA;
    u32 counterB;
} Ov000FadeBlock;

extern Ov000LoadContext *data_ov000_0205ac24;

extern void Ov000_MarkSceneReady(int slot);
extern int  Ov000_PollSaveCheck(void);
extern void Ov000_RecordLoadResult(int slot, int result);
extern int  GameState_GetField(int a, int b);

u8 Ov000_UpdateLoadState(int slot)
{
    Ov000LoadContext *ctx = data_ov000_0205ac24;

    switch (ctx->loadState) {
    case 0:
        ctx->slots[slot].current = ctx->slots[slot].base;
        Ov000_MarkSceneReady(slot);
        data_ov000_0205ac24->loadState = 1;
        break;
    case 1: {
        int result;
        result = Ov000_PollSaveCheck();
        if (result == 3) {
            data_ov000_0205ac24->loadState = 2;
            data_ov000_0205ac24->field_4adc = 3;
            ((Ov000FadeBlock *)data_ov000_0205ac24)->controlWord =
                (((Ov000FadeBlock *)data_ov000_0205ac24)->controlWord & 0xffff0000) | 1;
            ((Ov000FadeBlock *)data_ov000_0205ac24)->counterA = 0;
            ((Ov000FadeBlock *)data_ov000_0205ac24)->counterB = 0;
        } else if (result >= 0) {
            Ov000_RecordLoadResult(slot, result);
            data_ov000_0205ac24->loadState = 2;
            if (((Ov000FadeBlock *)data_ov000_0205ac24)->requestWord != 0) {
                if (GameState_GetField(0x44e, 3) == 6) {
                    ((Ov000FadeBlock *)data_ov000_0205ac24)->resultWord |= 1;
                }
            }
        }
        break;
    }
    }
    return data_ov000_0205ac24->loadState;
}
