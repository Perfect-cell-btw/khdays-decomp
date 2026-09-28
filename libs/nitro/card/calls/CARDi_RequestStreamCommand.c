/* NitroSDK CARDi_RequestStreamCommand (src, dst, len, callback, arg, async, type, retry, mode). */

typedef signed long s32;
typedef unsigned long u32;
typedef unsigned char u8;
typedef int BOOL;

enum {
    CARD_STAT_BUSY = 1 << 2
};

typedef void (*CARDCallback)(void *argument);

struct CARDiCommandArg {
    int result;
};

struct CARDiCommon {
    struct CARDiCommandArg *cmd;
    s32 command;
    volatile s32 lock_owner;
    volatile s32 lock_ref;
    u8 lock_queue[8];
    s32 lock_target;
    u32 src;
    u32 dst;
    u32 len;
    u32 dma;
    s32 req_type;
    s32 req_retry;
    s32 req_mode;
    CARDCallback callback;
    void *callback_arg;
    void (*task_func)(struct CARDiCommon *common);
    u8 thread[0xc0];
    void *cur_th;
    u32 priority;
    u8 busy_q[8];
    volatile u32 flag;
};

struct OSiThreadInfoPrefix {
    u32 initialized;
    void *current_thread;
};

extern void OSi_ReferSymbol(void *p);
extern int OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(int state);
extern void OS_SleepThread(void *queue);
extern void CARDi_SetTask(void (*task)(struct CARDiCommon *common));
extern void CARDi_RequestStreamCommandCore(struct CARDiCommon *common);
extern struct CARDiCommon data_020464e0;
extern struct OSiThreadInfoPrefix data_02044330;

static inline void Card_WaitTask(struct CARDiCommon *common,
                                 CARDCallback callback,
                                 void *callbackArgument)
{
    int interruptState = OS_DisableInterrupts();
    while ((common->flag & CARD_STAT_BUSY) != 0) {
        OS_SleepThread(common->busy_q);
    }
    common->flag |= CARD_STAT_BUSY;
    common->callback = callback;
    common->callback_arg = callbackArgument;
    OS_RestoreInterrupts(interruptState);
}

BOOL CARDi_RequestStreamCommand(u32 src, u32 dst, u32 len, CARDCallback callback,
                    void *callbackArgument, BOOL asynchronous,
                    s32 reqType, s32 reqRetry, s32 reqMode)
{
    struct CARDiCommon *const common = &data_020464e0;

    OSi_ReferSymbol((void *)0x02000b8c);
    Card_WaitTask(common, callback, callbackArgument);

    common->src = src;
    common->dst = dst;
    common->len = len;
    common->req_type = reqType;
    common->req_retry = reqRetry;
    common->req_mode = reqMode;

    if (asynchronous) {
        CARDi_SetTask(CARDi_RequestStreamCommandCore);
        return 1;
    }

    data_020464e0.cur_th = data_02044330.current_thread;
    CARDi_RequestStreamCommandCore(common);
    return (common->cmd->result == 0);
}
