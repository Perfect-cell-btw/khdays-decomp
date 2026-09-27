/* NitroSDK spi (pm.c): PMi_ReadRegisterAsync -- PXI command 0x65 (PM_REG_READ). */
typedef unsigned short u16;
typedef unsigned int u32;
typedef void (*PMCallback)(u32 result, void *argument);

typedef struct PMData16 {
    u16 flag;
    u16 padding;
    u16 *buffer;
} PMData16;

typedef struct PXIContext {
    unsigned char reserved_00[0x1c];
    u32 locked;
    PMCallback callback;
    void *callbackArgument;
} PXIContext;

extern int PMi_Lock(void);
extern void PMi_SendPxiData(u32 command);
extern PXIContext data_020463cc;
extern PMData16 data_02046410[];

u32 PMi_ReadRegisterAsync(u16 channel, u16 *buffer,
                        PMCallback callback, void *callbackArgument)
{
    if (PMi_Lock() == 0) {
        return 1;
    }

    data_020463cc.callback = callback;
    data_020463cc.callbackArgument = callbackArgument;
    data_02046410[channel].flag = 0;
    data_02046410[channel].buffer = buffer;
    PMi_SendPxiData((channel & 0xff) | 0x03006500);
    return 0;
}
