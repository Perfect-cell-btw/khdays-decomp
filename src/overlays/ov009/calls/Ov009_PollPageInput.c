typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct Ov009InputContext {
    u8 pad_0000[0x959c];
    void *pageA;
    void *pageB;
    u8 pad_95a4[0x95fc - 0x95a4];
    int inputEnabled;
    int pageAEnabled;
    int pageBEnabled;
    u8 pad_9608[0x9610 - 0x9608];
    u16 buttonState;
    u8 pad_9612[0x963e - 0x9612];
    u16 inputSource;
} Ov009InputContext;

extern Ov009InputContext *volatile data_ov009_020563e4[];
extern u16 data_0204c190;

#define OV009_CONTEXT (data_ov009_020563e4[1])

extern u16 Mem_ReadU16(const u16 *source);
extern int Ov009_MenuInputDispatch_00(void *pageA, void *pageB);
extern int Ov009_MenuInputDispatch_01(void *pageA, void *pageB);
extern int Ov009_MenuInputDispatch_02(void *pageA, void *pageB);
extern int Ov009_MenuInputDispatch_03(void *pageA, void *pageB);
extern int Ov009_MenuInputDispatch_04(void *pageA, void *pageB);
extern int Ov009_MenuInputDispatch_05(void *pageA, void *pageB);
extern int Ov009_MenuInputDispatch_06(void *pageA, void *pageB);
extern int Ov009_MenuInputDispatch_07(void *pageA, void *pageB);
extern int Ov009_MenuInputDispatch_08(void *pageA, void *pageB);
extern int Ov009_MenuInputDispatch_09(void *pageA, void *pageB);
extern int Ov009_MenuInputDispatch_10(void *pageA, void *pageB);
extern int Ov009_MenuInputDispatch_11(void *pageA, void *pageB);

void Ov009_PollPageInput(void)
{
    Ov009InputContext *context = OV009_CONTEXT;
    void *pageA = context->pageAEnabled ? context->pageA : 0;
    void *pageB = context->pageBEnabled ? context->pageB : 0;

    if (context->inputEnabled == 0) {
        return;
    }

    if ((Mem_ReadU16(&context->inputSource) & 0x40) != 0 &&
        Ov009_MenuInputDispatch_00(pageA, pageB) != 0) {
        return;
    }
    if ((Mem_ReadU16(&OV009_CONTEXT->inputSource) & 0x80) != 0 &&
        Ov009_MenuInputDispatch_01(pageA, pageB) != 0) {
        return;
    }
    if ((Mem_ReadU16(&OV009_CONTEXT->inputSource) & 0x20) != 0 &&
        Ov009_MenuInputDispatch_02(pageA, pageB) != 0) {
        return;
    }
    if ((Mem_ReadU16(&OV009_CONTEXT->inputSource) & 0x10) != 0 &&
        Ov009_MenuInputDispatch_03(pageA, pageB) != 0) {
        return;
    }

    if ((data_0204c190 & 0x0001) != 0 &&
        Ov009_MenuInputDispatch_04(pageA, pageB) != 0) {
        return;
    }
    if ((data_0204c190 & 0x0002) != 0 &&
        Ov009_MenuInputDispatch_05(pageA, pageB) != 0) {
        return;
    }
    if ((data_0204c190 & 0x0400) != 0 &&
        Ov009_MenuInputDispatch_06(pageA, pageB) != 0) {
        return;
    }
    if ((data_0204c190 & 0x0800) != 0 &&
        Ov009_MenuInputDispatch_07(pageA, pageB) != 0) {
        return;
    }
    if ((data_0204c190 & 0x0200) != 0 &&
        Ov009_MenuInputDispatch_08(pageA, pageB) != 0) {
        return;
    }
    if ((data_0204c190 & 0x0100) != 0 &&
        Ov009_MenuInputDispatch_09(pageA, pageB) != 0) {
        return;
    }
    if ((data_0204c190 & 0x0004) != 0 &&
        Ov009_MenuInputDispatch_10(pageA, pageB) != 0) {
        return;
    }
    if ((data_0204c190 & 0x0008) != 0 &&
        Ov009_MenuInputDispatch_11(pageA, pageB) != 0) {
        return;
    }

    OV009_CONTEXT->buttonState =
        (data_0204c190 & 0x2f0f) |
        (Mem_ReadU16(&OV009_CONTEXT->inputSource) & 0x00f0);
}
