/* Per-frame camp-menu manager: creates and runs the current page handler, starts the secondary
 * handler the story state calls for (tutorial cues, flags), and runs it. */

extern int data_ov008_02090f04[];

#define CTXV (*(int *)((char *)data_ov008_02090f04 + 4))

typedef struct Ov008UiContextTail {
    char pad_0000[0x959c];
    void *pageA;
    void *pageB;
    char pad_95a4[0x20];
    int mode;
    char pad_95c8[0x30];
    int secondaryEnabled;
    char pad_95fc[0x1c];
    int taskPending;
    int refreshPending;
    int pageAHandle;
    int pageBHandle;
} Ov008UiContextTail;

extern int Ov008_SetHandlerA(int mode);
extern int Ov008_HandlerA_GetField10(void);
extern void *NNSi_FndAllocFromDefaultExpHeap(int size);
extern void MI_CpuFill8(void *destination, int value, int size);
extern int Ov008_InvokeHandlerA(int object);
extern void Ov008_HandlerA_Call2(int object);
extern int GameState_IsFlagSet(int flagId);
extern int Ov008_GetCtxObject95c0(void);
extern int Ov008_ArmCueRequest(int duration, int b, int c);
extern int Ov008_SetHandlerB(int value);
extern void GameState_SetFlag(int flagId);
extern void Ov008_SetCtxFields9638And963a(int x, int y);
extern int Ov008_HandlerA_GetField0C(void);
extern int Ov008_HandlerB_GetField0C(void);
extern int Ov008_InvokeHandlerB(int object);
extern void Ov008_HandlerB_Call2(int object);
extern void Ov008_BlitConfigRegion(int value, unsigned int duration);
extern void Ov008_SetCtxField95cc(int value);
extern void RegisterNamedTask(int priority, const char *name, void (*callback)(void));
extern char data_ov008_02090024[];
extern void Ov008_UpdateBrightnessAndCallbacks(void);

void Ov008_UpdateCampaignMenuManager(void)
{
    Ov008UiContextTail *context;
    int size;

    context = (Ov008UiContextTail *)CTXV;
    if (context->pageA == 0) {
        Ov008_SetHandlerA(context->mode);
        size = Ov008_HandlerA_GetField10();
        *(void **)(CTXV + 0x959c) = NNSi_FndAllocFromDefaultExpHeap(size);
        MI_CpuFill8(*(void **)(CTXV + 0x959c), 0, size);
    }

    if (*(int *)(CTXV + 0x9620) == 0) {
        *(int *)(CTXV + 0x9620) =
            Ov008_InvokeHandlerA(*(int *)(CTXV + 0x959c));
    } else {
        Ov008_HandlerA_Call2(*(int *)(CTXV + 0x959c));
    }

    if (*(int *)(CTXV + 0x95f8) != 0) {
        if (*(int *)(CTXV + 0x95a0) == 0) {
            if (*(int *)(CTXV + 0x95c4) == 2 &&
                GameState_IsFlagSet(0x35bc) == 0 &&
                Ov008_GetCtxObject95c0() != 2) {
                Ov008_ArmCueRequest(0xe, 0, 0);
                Ov008_SetHandlerB(4);
                GameState_SetFlag(0x35bc);
            } else if (*(int *)(CTXV + 0x95c4) == 1 &&
                       *(int *)(CTXV + 0x9630) != 0 &&
                       *(int *)(CTXV + 0x9634) == 0 &&
                       Ov008_GetCtxObject95c0() != 2) {
                Ov008_SetCtxFields9638And963a(0, 0);
                Ov008_SetHandlerB(5);
            } else if (*(int *)(CTXV + 0x95c4) == 1 &&
                       Ov008_GetCtxObject95c0() == 2 &&
                       GameState_IsFlagSet(0x200a) != 0) {
                Ov008_SetHandlerB(2);
            } else {
                Ov008_SetHandlerB(Ov008_HandlerA_GetField0C());
            }

            size = Ov008_HandlerB_GetField0C();
            *(void **)(CTXV + 0x95a0) = NNSi_FndAllocFromDefaultExpHeap(size);
            MI_CpuFill8(*(void **)(CTXV + 0x95a0), 0, size);
        }

        if (*(int *)(CTXV + 0x9624) == 0) {
            *(int *)(CTXV + 0x9624) =
                Ov008_InvokeHandlerB(*(int *)(CTXV + 0x95a0));
        } else {
            Ov008_HandlerB_Call2(*(int *)(CTXV + 0x95a0));
        }
    }

    context = (Ov008UiContextTail *)CTXV;
    if (context->pageAHandle != 0 && context->pageBHandle != 0) {
        if (context->refreshPending != 0) {
            context->refreshPending = 0;
            Ov008_BlitConfigRegion(0, 100);
        } else {
            Ov008_BlitConfigRegion(0, 100);
        }
        Ov008_SetCtxField95cc(2);
    }

    if (*(int *)(CTXV + 0x9618) != 0) {
        RegisterNamedTask(1, data_ov008_02090024, Ov008_UpdateBrightnessAndCallbacks);
        *(int *)(CTXV + 0x9618) = 0;
    }
}

