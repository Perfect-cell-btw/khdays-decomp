/* Waits for the local player's action to settle (sound, element list, crawl score), then re-anchors
 * the camera on the actor, resets the member and fades in; returns the finish-action step. */

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

typedef void *(*Ov022StateCallback)(void);

typedef struct Ov022Context {
    u16 flags;
    char pad_0002[6];
    void *slots[3];
    void *childObjects[2];
    int viewX;
    int viewY;
    char pad_0024[0x1a];
    s8 state;
} Ov022Context;

typedef struct Ov022Entity {
    char pad_0000[0x2668];
    void *pendingObject;
} Ov022Entity;

extern Ov022Context *data_ov022_020b2e60;
extern u8 data_0204be04;

extern int func_ov022_02083f0c(void);
extern void Ov022_SetActorInputEnabled(int mode);
extern int func_020335c8(void);
extern int SoundMgr_IsState1(void);
extern int Ov002_ElementList_IsEmpty(void);
extern int Ov002_GetRootField8b68Alt(void);
extern int QueryActiveStateOrDelegate(void);
extern int Ov022_GetEntryField66(int index);
extern int Ov002_PostCrawlScoreLine(int worldId);
extern int Ov002_GetRootField8d64(void);
extern unsigned short func_ov022_02088254(int index);
extern void Ov002_Camera_SetOrbitAngle(int actor, int angle);
extern int func_ov022_020881f8(int index);
extern void Ov002_Camera_SetAnchor(int actor, const void *origin);
extern void Ov002_SetRootSlot0x8d64(int value);
extern void Ov002_FireSlotHook(int index, int argument);
extern void Ov022_Member_Reset(int index);
extern Ov022Entity *GetEntryField20ByIndex(int index);
extern void Ov002_SetSessionActive(int kind, int value);
extern void Ov022_SetBit3OnPtr20(void *object, int enabled);
extern void SetMasterBrightnessSub(int brightness);
extern void Ov002_InitRefreshWindow(void);
extern int func_0201e428(void);
extern int func_0201e438(void);

extern void *func_ov022_0208310c(void);
extern void *Ov022_StateFinishAction(void);

Ov022StateCallback Ov022_StateWaitForAction(void)
{
    Ov022Context *context = data_ov022_020b2e60;
    int actor = func_ov022_02083f0c();
    int angle;
    Ov022Entity *entity;
    void *pendingObject;

    if ((context->flags & 0x20) != 0) {
        Ov022_SetActorInputEnabled(1);
        return func_ov022_0208310c;
    }
    if (data_0204be04 != 0) {
        return 0;
    }

    Ov022_SetActorInputEnabled(1);
    if ((context->flags & 8) != 0) {
        return 0;
    }
    if (func_020335c8() != 0 || SoundMgr_IsState1() != 0) {
        return 0;
    }
    if (Ov002_ElementList_IsEmpty() == 0) {
        return 0;
    }
    if (Ov002_GetRootField8b68Alt() != 0 && (context->flags & 0x200) == 0) {
        return 0;
    }
    if (Ov002_PostCrawlScoreLine(Ov022_GetEntryField66(QueryActiveStateOrDelegate())) == 0) {
        return 0;
    }

    angle = Ov002_GetRootField8d64();
    if (angle < 0) {
        angle = func_ov022_02088254(QueryActiveStateOrDelegate());
    }
    Ov002_Camera_SetOrbitAngle(actor, angle);
    Ov002_Camera_SetAnchor(actor, (const void *)func_ov022_020881f8(QueryActiveStateOrDelegate()));
    Ov002_SetRootSlot0x8d64(-1);
    Ov002_FireSlotHook(Ov022_GetEntryField66(QueryActiveStateOrDelegate()), 1);
    Ov022_Member_Reset(QueryActiveStateOrDelegate());

    entity = GetEntryField20ByIndex(QueryActiveStateOrDelegate());
    pendingObject = entity->pendingObject;
    if (pendingObject != 0 && *(u8 *)pendingObject == 0) {
        GetEntryField20ByIndex(QueryActiveStateOrDelegate())->pendingObject = 0;
    }

    Ov002_SetSessionActive(0, 2);
    Ov022_SetBit3OnPtr20(context->slots[0], 0);

    if (context->state != 0) {
        if (context->state == 2) {
            context->viewY = -0x10000;
            SetMasterBrightnessSub(context->viewY >> 12);
            Ov002_InitRefreshWindow();
        }
    } else {
        context->viewX = func_0201e428() << 12;
        context->viewY = func_0201e438() << 12;
    }

    return Ov022_StateFinishAction;
}
