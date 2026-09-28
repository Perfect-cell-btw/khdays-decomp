/* Allocates and loads page A, blits it, sets mode 2 and registers the per-frame tick. */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef struct Ov009MenuContext {
    u8 pad_0000[0x959c];
    void *pageA;
    u8 pad_95a0[0x95c4 - 0x95a0];
    int pageInitArg;
    u8 pad_95c8[0x9618 - 0x95c8];
    int updateTaskPending;
    int blitPending;
    void *pageResource;
    int pageResourceReady;
} Ov009MenuContext;

extern Ov009MenuContext *data_ov009_020563e4[];
extern const char data_ov009_02056294[];

#define OV009_CONTEXT (data_ov009_020563e4[1])
#define OV009_CONTEXT_VOLATILE \
    (*(Ov009MenuContext *volatile *)&data_ov009_020563e4[1])

extern void  Ov009_SetHandlerA(int initArg);
extern u32   Ov009_HandlerA_GetField10(void);
extern void *NNSi_FndAllocFromDefaultExpHeap(u32 size);
extern void  MI_CpuFill8(void *destination, int value, u32 size);
extern void *Ov009_InvokeHandlerA(void *page);
extern void  Ov009_HandlerA_Call2(void *page);
extern void  Ov009_BlitConfigRegion(int sourceOffset, int size);
extern void  Ov009_SetCtxField95cc(int state);
extern void  RegisterNamedTask(int priority, const void *descriptor,
                          void (*callback)(void));
extern void  Ov009_Menu_VBlankTick(void);

void Ov009_Menu_PreparePage(void)
{
    u32 pageSize;

    if (OV009_CONTEXT->pageA == 0) {
        Ov009_SetHandlerA(OV009_CONTEXT->pageInitArg);
        pageSize = Ov009_HandlerA_GetField10();
        OV009_CONTEXT_VOLATILE->pageA =
            NNSi_FndAllocFromDefaultExpHeap(pageSize);
        MI_CpuFill8(OV009_CONTEXT_VOLATILE->pageA, 0, pageSize);
    }

    if (OV009_CONTEXT->pageResource == 0) {
        OV009_CONTEXT->pageResource =
            Ov009_InvokeHandlerA(OV009_CONTEXT->pageA);
    } else {
        Ov009_HandlerA_Call2(OV009_CONTEXT->pageA);
    }

    OV009_CONTEXT_VOLATILE->pageResourceReady = 1;

    {
        Ov009MenuContext *context = OV009_CONTEXT_VOLATILE;
        if (context->pageResource != 0 &&
            context->pageResourceReady != 0) {
            if (context->blitPending != 0) {
                context->blitPending = 0;
                Ov009_BlitConfigRegion(0, 100);
            } else {
                Ov009_BlitConfigRegion(0, 100);
            }
            Ov009_SetCtxField95cc(2);
        }
    }

    if (OV009_CONTEXT->updateTaskPending != 0) {
        RegisterNamedTask(
            1, data_ov009_02056294, Ov009_Menu_VBlankTick);
        OV009_CONTEXT->updateTaskPending = 0;
    }
}
