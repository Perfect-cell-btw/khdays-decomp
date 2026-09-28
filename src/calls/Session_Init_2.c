typedef unsigned int u32;

struct Foo {
    u32 _00;
    u32 _04;
    u32 _08;
    u32 arr[23];
    u32 _68;
    u32 _6c;
};

extern struct Foo *NNSi_FndGetCurrentRootHeap(void);
extern u32 func_0203065c(void);
extern void Session_LayoutPacketSlots(void);
extern void MsgQueue_Init(void);
extern void Ov105_SetSlotEventHandler(u32 a, void *b, u32 c);
extern void SubmitEntryIfActive(void);
extern void DrawTileIfReady(void);
extern void EffectList_StepIfIdle(void);

extern struct Foo *data_0204c22c;

void (*Session_Init_2(void))(void)
{
    struct Foo *p;
    u32 r;
    int i;

    p = NNSi_FndGetCurrentRootHeap();
    data_0204c22c = p;
    func_0203065c();
    Session_LayoutPacketSlots();
    p->_6c = 0;
    p->_68 = 0;
    for (i = 0; i < 20; i++) {
        p->arr[i] = 0;
    }
    MsgQueue_Init();
    r = func_0203065c();
    switch (r) {
    case 2:
        Ov105_SetSlotEventHandler(12, SubmitEntryIfActive, 0);
        break;
    case 3:
        Ov105_SetSlotEventHandler(12, DrawTileIfReady, 0);
        break;
    }
    p->_00 = 0;
    return EffectList_StepIfIdle;
}
