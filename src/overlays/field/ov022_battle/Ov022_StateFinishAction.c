/* Finishes an action: fades both screens back in (or waits for the scene) and returns to the
 * gameplay hub when input is free. */

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

typedef void *(*Ov022StateCallback)(void);

typedef struct Ov022Context {
    u16 flags;
    char pad_0002[0x1a];
    int viewX;
    int viewY;
    char pad_0024[0x1a];
    s8 state;
} Ov022Context;

extern Ov022Context *data_ov022_020b2e60;
extern u8 data_0204be04;

extern void Ov022_SetActorInputEnabled(int mode);
extern int Ov002_Scene_IsIdle(void);
extern int func_02023c40(void);
extern void SetMasterBrightnessMain(int brightness);
extern void SetMasterBrightnessSub(int brightness);
extern int Ov002_IsInputBlocked(void);

extern void *func_ov022_0208310c(void);
extern void *Ov022_StateGameplayHub(void);

Ov022StateCallback Ov022_StateFinishAction(void)
{
    Ov022StateCallback next = 0;
    Ov022Context *context = data_ov022_020b2e60;
    int completed = 0;

    if ((context->flags & 0x20) != 0) {
        Ov022_SetActorInputEnabled(1);
        return func_ov022_0208310c;
    }
    if (data_0204be04 != 0) {
        return next;
    }

    Ov022_SetActorInputEnabled(1);
    if ((context->flags & 8) != 0) {
        return next;
    }

    if (context->state != 0) {
        if (context->state == 2 && Ov002_Scene_IsIdle() != 0) {
            completed = 1;
        }
    } else {
        context->viewX += func_02023c40() == 1 ? 0x3000 : 0x2000;
        if (context->viewX >= 0) {
            context->viewX = 0;
            completed = 1;
        }
        context->viewY = context->viewX;
        SetMasterBrightnessMain(context->viewX >> 12);
        SetMasterBrightnessSub(context->viewY >> 12);
    }

    if (completed != 0) {
        if (Ov002_IsInputBlocked() == 0) {
            return 0;
        }
        context->state = -1;
        context->flags &= ~0x10;
        next = Ov022_StateGameplayHub;
    }

    return next;
}
