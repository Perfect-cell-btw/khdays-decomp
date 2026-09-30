/* Per-frame camp-menu manager: creates and runs the current page handler, starts the secondary
 * handler the story state calls for (tutorial cues, flags), and runs it. */

extern int data_ov025_020b5744[];

#define CTXV (*(int *)((char *)data_ov025_020b5744 + 4))

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

extern int Ov025_SetHandlerA(int mode);
extern int Ov025_HandlerA_GetField10(void);
extern void *NNSi_FndAllocFromDefaultExpHeap(int size);
extern void MI_CpuFill8(void *destination, int value, int size);
extern int Ov025_InvokeHandlerA(int object);
extern void Ov025_HandlerA_Call2(int object);
extern int GameState_IsFlagSet(int flagId);
extern int Ov025_GetCtxObject95c0(void);
extern int Ov025_ArmCueRequest(int duration, int b, int c);
extern int Ov025_SetHandlerB(int value);
extern void GameState_SetFlag(int flagId);
extern void Ov025_SetCtxFields9638And963a(int x, int y);
extern int Ov025_HandlerA_GetField0C(void);
extern int Ov025_HandlerB_GetField0C(void);
extern int Ov025_InvokeHandlerB(int object);
extern void Ov025_HandlerB_Call2(int object);
extern void Ov025_BlitConfigRegion(int value, unsigned int duration);
extern void Ov025_SetCtxField95cc(int value);
extern void RegisterNamedTask(int priority, const char *name, void (*callback)(void));
extern char gOv025CampmenumngrName[];
extern void Ov025_UpdateBrightnessAndCallbacks(void);

void Ov025_UpdateCampaignMenuManager(void)
{
    Ov008UiContextTail *context;
    int size;

    context = (Ov008UiContextTail *)CTXV;
    if (context->pageA == 0) {
        Ov025_SetHandlerA(context->mode);
        size = Ov025_HandlerA_GetField10();
        *(void **)(CTXV + 0x959c) = NNSi_FndAllocFromDefaultExpHeap(size);
        MI_CpuFill8(*(void **)(CTXV + 0x959c), 0, size);
    }

    if (*(int *)(CTXV + 0x9620) == 0) {
        *(int *)(CTXV + 0x9620) =
            Ov025_InvokeHandlerA(*(int *)(CTXV + 0x959c));
    } else {
        Ov025_HandlerA_Call2(*(int *)(CTXV + 0x959c));
    }

    if (*(int *)(CTXV + 0x95f8) != 0) {
        if (*(int *)(CTXV + 0x95a0) == 0) {
            if (*(int *)(CTXV + 0x95c4) == 2 &&
                GameState_IsFlagSet(0x35bc) == 0 &&
                Ov025_GetCtxObject95c0() != 2) {
                Ov025_ArmCueRequest(0xe, 0, 0);
                Ov025_SetHandlerB(4);
                GameState_SetFlag(0x35bc);
            } else if (*(int *)(CTXV + 0x95c4) == 1 &&
                       *(int *)(CTXV + 0x9630) != 0 &&
                       *(int *)(CTXV + 0x9634) == 0 &&
                       Ov025_GetCtxObject95c0() != 2) {
                Ov025_SetCtxFields9638And963a(0, 0);
                Ov025_SetHandlerB(5);
            } else if (*(int *)(CTXV + 0x95c4) == 1 &&
                       Ov025_GetCtxObject95c0() == 2 &&
                       GameState_IsFlagSet(0x200a) != 0) {
                Ov025_SetHandlerB(2);
            } else {
                Ov025_SetHandlerB(Ov025_HandlerA_GetField0C());
            }

            size = Ov025_HandlerB_GetField0C();
            *(void **)(CTXV + 0x95a0) = NNSi_FndAllocFromDefaultExpHeap(size);
            MI_CpuFill8(*(void **)(CTXV + 0x95a0), 0, size);
        }

        if (*(int *)(CTXV + 0x9624) == 0) {
            *(int *)(CTXV + 0x9624) =
                Ov025_InvokeHandlerB(*(int *)(CTXV + 0x95a0));
        } else {
            Ov025_HandlerB_Call2(*(int *)(CTXV + 0x95a0));
        }
    }

    context = (Ov008UiContextTail *)CTXV;
    if (context->pageAHandle != 0 && context->pageBHandle != 0) {
        if (context->refreshPending != 0) {
            context->refreshPending = 0;
            Ov025_BlitConfigRegion(0, 100);
        } else {
            Ov025_BlitConfigRegion(0, 100);
        }
        Ov025_SetCtxField95cc(2);
    }

    if (*(int *)(CTXV + 0x9618) != 0) {
        RegisterNamedTask(1, gOv025CampmenumngrName, Ov025_UpdateBrightnessAndCallbacks);
        *(int *)(CTXV + 0x9618) = 0;
    }
}

