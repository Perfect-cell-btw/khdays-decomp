

#include "nitro/types.h"
#include "nitro/os.h"

#define offsetof(type, member) ((u32)&(((type *)0)->member))

#define SDK_THREAD_INFINITY 1

extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern void OSi_RescheduleThread(void);
extern void OSi_InsertLinkToQueue (OSThreadQueue * queue, OSThread * thread);
extern void OSi_RescheduleThread (void);

/* khdays: shared-bss */
u32 OSi_ThreadIdCount = 0;   /* OSi_ThreadIdCount */
void * OSi_StackForDestructor = 0;   /* OSi_StackForDestructor */
u32 OSi_SystemStackBuffer = 0;   /* OSi_SystemStackBuffer */
vu32 killThreadStatus = 0;   /* killThreadStatus */
vu32 exitThreadStatus = 0;   /* exitThreadStatus */
BOOL OSi_IsThreadInitialized = 0;   /* OSi_IsThreadInitialized */
OSThread ** OSi_CurrentThreadPtr = 0;   /* OSi_CurrentThreadPtr */
u32 OSi_RescheduleCount = 0;   /* OSi_RescheduleCount */
void * data_0204430c = 0;   /* data_0204430c */
OSThreadInfo data_02044330 = {0};   /* data_02044330 */

/* OS_SleepThread -- NitroSDK os_thread.c: OS_SleepThread. */
void OS_SleepThread (OSThreadQueue * queue)
{
    OSIntrMode enable;
    OSThread * currentThread;

    enable = OS_DisableInterrupts();
#ifndef SDK_THREAD_INFINITY
    {
        currentThread = OSi_GetCurrentThread();

        if (queue) {
            *queue |= (OSThreadQueue)(1UL << currentThread->id);
        }

        currentThread->state = OS_THREAD_STATE_WAITING;
        OSi_RescheduleThread();
    }
#else
    {
        currentThread = OSi_GetCurrentThread();

        if (queue) {
            currentThread->queue = queue;
            OSi_InsertLinkToQueue(queue, currentThread);
        }

        currentThread->state = OS_THREAD_STATE_WAITING;
        OSi_RescheduleThread();
    }
#endif
    (void)OS_RestoreInterrupts(enable);

}
