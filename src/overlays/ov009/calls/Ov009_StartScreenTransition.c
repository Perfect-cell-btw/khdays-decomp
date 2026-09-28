typedef unsigned char u8;

typedef struct MenuContext {
    u8 pad0000[0x95c4];
    int transitionValue;
    u8 pad95c8[0x30];
    int transitionActive;
} MenuContext;

extern MenuContext *volatile data_ov009_020563e4[2];
extern int func_ov009_0204ee00(void);
extern void Ov009_SetCtxField95cc(int mode);
extern void Ov009_BlitConfigRegion(int brightness, int duration);
extern void Ov009_EnableBothHalves(int enabled);

void Ov009_StartScreenTransition(int value, int duration)
{
    int state = func_ov009_0204ee00();

    data_ov009_020563e4[1]->transitionValue = value;
    if (state == -1) {
        Ov009_SetCtxField95cc(1);
        data_ov009_020563e4[1]->transitionActive = 1;
        return;
    }

    if (duration < 0) {
        duration = 100;
    }
    Ov009_SetCtxField95cc(4);
    Ov009_BlitConfigRegion(-0x10, duration);
    Ov009_EnableBothHalves(0);
    data_ov009_020563e4[1]->transitionActive = 0;
}
