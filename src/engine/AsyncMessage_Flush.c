/* Sends or applies the pending message according to the session mode, then clears it; returns 1
 * when there was one. */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct AsyncMessage {
    int active00;
    void *data04;
    u16 size08;
} AsyncMessage;

extern int Session_GetLinkMode(void);
extern u16 GetGlobalU16At4(void);
extern void ClearNodeIfHeadMatches(void);
extern int Ov105_WM_SetMPDataToPortEx(void (*callback)(void), AsyncMessage *message,
                              void *data, u16 size, u16 mask, int stride,
                              int zero);
extern void AsyncMessage_FlushHookNoOp(void);
extern void dispatchByObjTypeBits(void *data, u16 size);

int AsyncMessage_Flush(AsyncMessage *message)
{
    int result;

    if (message->size08 == 0) {
        return 0;
    }

    switch (Session_GetLinkMode()) {
    case 2:
        message->active00 = 1;
        result = Ov105_WM_SetMPDataToPortEx(ClearNodeIfHeadMatches, message,
                                    message->data04, message->size08,
                                    GetGlobalU16At4() & 0xfffe, 12, 0);
        if (result != 2) {
            AsyncMessage_FlushHookNoOp();
        }
        dispatchByObjTypeBits(message->data04, message->size08);
        break;
    case 1:
        dispatchByObjTypeBits(message->data04, message->size08);
        break;
    case 3:
        message->active00 = 1;
        result = Ov105_WM_SetMPDataToPortEx(ClearNodeIfHeadMatches, message,
                                    message->data04, message->size08,
                                    0, 12, 0);
        if (result != 2) {
            AsyncMessage_FlushHookNoOp();
        }
        break;
    }

    message->size08 = 0;
    return 1;
}
