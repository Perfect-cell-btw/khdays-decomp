

#include "nitro/types.h"
#include "nitro/os.h"

#define offsetof(type, member) ((u32)&(((type *)0)->member))

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

/* OSi_RemoveThreadFromList -- NitroSDK os_thread.c: OSi_RemoveThreadFromList. */
void OSi_RemoveThreadFromList (OSThread * thread)
{
    OSThread * t = data_02044330.list;
    OSThread * pre = NULL;

    while (t && t != thread) {
        pre = t;
        t = t->next;
    }

    if (!pre) {
        data_02044330.list = thread->next;
    } else {
        pre->next = thread->next;
    }
}
