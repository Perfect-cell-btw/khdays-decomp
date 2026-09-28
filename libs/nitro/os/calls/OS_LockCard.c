/* NitroSDK os (os_spinLock.c): OS_LockCard -- OS_LockByWord on the card lock buffer with OSi_AllocateCardBus. */
#include "nitro/types.h"

typedef struct OSLockWord {
    u16 lockFlag;
    u16 extension;
} OSLockWord;

typedef void (*OSLockCallback)(void);

extern void OS_LockByWord(u16 lockId, OSLockWord *lock, OSLockCallback onFree);
extern void OSi_AllocateCardBus(void);

/* The card lock word lives at a fixed address in the shared region, so its
   address is a plain literal rather than a relocated symbol. */
#define OSi_CardLock ((OSLockWord *)0x027fffe0)

void OS_LockCard(u16 lockId)
{
    OS_LockByWord(lockId, OSi_CardLock, OSi_AllocateCardBus);
}
