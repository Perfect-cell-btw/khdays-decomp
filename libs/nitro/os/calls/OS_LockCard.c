/* NitroSDK os (os_spinLock.c): OS_LockCard -- OS_LockByWord on the card lock buffer with OSi_AllocateCardBus. */

#include "nitro/types.h"
#include "nitro/os.h"

extern void OS_LockByWord(int lockId, OSLockWord *lock, OSLockCallback onFree);
extern void OSi_AllocateCardBus(void);

/* The card lock word lives at a fixed address in the shared region, so its
   address is a plain literal rather than a relocated symbol. */

void OS_LockCard(u16 lockId)
{
    OS_LockByWord(lockId, OSi_CardLock, OSi_AllocateCardBus);
}
