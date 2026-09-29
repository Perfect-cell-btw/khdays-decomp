/* Main battle state: waits out its delay, runs the frame, updates progress flags and picks the next
 * state (action, results, leave, crawl skip) from the context flags and players. */

#include "nitro/types.h"
#include "game/engine.h"

typedef void *(*Ov022StateCallback)(void);

typedef struct Ov022Context {
    u16 flags;
    char pad_0002[2];
    int delay;
    char pad_0008[0x36];
    s8 state;
} Ov022Context;

extern Ov022Context *data_ov022_020b2e60;
extern u8 data_0204c240;

extern int func_ov022_02083f0c(void);
extern void Ov022_UpdateCameraAndViews(int mode);
extern int func_ov022_02086ef4(void);
extern int func_ov022_02086f24(void);
extern void Ov022_SetGlobalC0(void);
extern int func_ov022_020886d0(int index);
extern int Ov002_GetRootField8b68Alt(void);
extern void Ov002_SetSessionBusy(int busy);
extern int func_ov022_02088648(void);
extern int Ov002_IsLeaveFinished(void);
extern unsigned int func_ov022_02088668(void);
extern int Ov022_GetEntryField12(int index);
extern void Ov002_RequestCrawlSkip(void);

extern void *func_ov022_0208310c(void);
extern void *Ov022_StateBeginResultSequence(void);
extern void *Ov022_StateWaitForAction(void);
extern void *func_ov022_020834d8(void);

Ov022StateCallback Ov022_StateGameplayHub(void)
{
    Ov022Context *context = data_ov022_020b2e60;
    Ov022StateCallback next = 0;

    func_ov022_02083f0c();
    GetEntryField20ByIndex(QueryActiveStateOrDelegate());

    if ((context->flags & 2) != 0) {
        return next;
    }
    if (context->delay > 0) {
        context->delay--;
        return next;
    }

    Ov022_UpdateCameraAndViews(1);

    if (func_ov022_02086ef4() != 0 && func_ov022_02086f24() != 0) {
        if (GameState_IsFlagSet(0x2085) == 0) {
            GameState_SetFlag(0x2085);
        }
    } else if (func_ov022_02086ef4() == 0 &&
               GameState_IsFlagSet(0x2086) != 0 &&
               GameState_IsFlagSet(0x2085) == 0) {
        GameState_SetFlag(0x2085);
    }

    if ((context->flags & 0x20) > 0) {
        if (func_ov022_02086ef4() != 0) {
            if (GameState_IsFlagSet(0x2085) == 0) {
                GameState_SetFlag(0x2085);
            }
            if ((data_ov022_020b2e60->flags & 0x40) == 0 &&
                func_ov022_02086f24() == 0) {
                return 0;
            }
        }
        return func_ov022_0208310c;
    }

    if ((context->flags & 0x80) > 0) {
        return 0;
    }

    if ((context->flags & 0x40) > 0 && func_ov022_02086ef4() != 0) {
        Ov022_SetGlobalC0();
        context->flags &= ~0x40;
    }

    if ((context->flags & 8) == 0 &&
        func_ov022_020886d0(QueryActiveStateOrDelegate()) != 0 &&
        ((data_0204c240 & 4) != 0 || Ov002_GetRootField8b68Alt() == 0)) {
        if ((data_0204c240 & 4) == 0) {
            Ov002_SetSessionBusy(1);
        }
        return Ov022_StateBeginResultSequence;
    }

    if (context->state >= 0) {
        return Ov022_StateWaitForAction;
    }

    if (func_ov022_02088648() != 0 &&
        (context->flags & 8) <= 0 &&
        Ov002_IsLeaveFinished() != 0 &&
        func_ov022_02088668() != 0 &&
        Ov022_GetEntryField12(QueryActiveStateOrDelegate()) > 0) {
        if (func_ov022_02086ef4() != 0 &&
            (data_ov022_020b2e60->flags & 0x40) == 0 &&
            func_ov022_02086f24() == 0) {
            return 0;
        }

        context->flags |= 0x100;
        func_02020878(0);
        if ((data_0204c240 & 4) != 0) {
            Callbacks_SetByte(0);
        }
        context->flags |= 0x10;
        if ((data_0204c240 & 4) == 0) {
            Ov002_SetSessionBusy(1);
        }
        Ov002_RequestCrawlSkip();
        next = func_ov022_020834d8;
    }

    return next;
}
