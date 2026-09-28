/* NitroSDK snd_command.c: PxiFifoCallback, the sound PXI callback SND_CommandInit registers for
 * tag 7. The ARM7 posts alarm messages here (alarmNo | id << 8); they are handed to the alarm
 * handler with interrupts disabled. */

#include "nitro/types.h"
#include "nitro/os_types.h"

typedef int PXIFifoTag;

extern OSIntrMode OS_DisableInterrupts(void);
extern void SNDi_CallAlarmHandler(int data);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);

void PxiFifoCallback(PXIFifoTag tag, u32 data, BOOL err)
{
    OSIntrMode enabled;
    (void)tag;
    (void)err;
    enabled = OS_DisableInterrupts();
    SNDi_CallAlarmHandler((int)data);
    (void)OS_RestoreInterrupts(enabled);
}
