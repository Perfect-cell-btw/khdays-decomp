/* Once the menu is ready, starts the reward multiplier presentation when it applies, otherwise goes
 * straight to the list. */

typedef unsigned char u8;
typedef struct Ov005Context {
    char opaque00[0x4bf0];
    int menuState;
    char opaque4bf4[0x38];
    int menuEntryReady;
    char opaque4c30[0x5c];
    u8 statusStep;
    char opaque4c8d[3];
    int rowItemCounts[2];
} Ov005Context;
typedef struct Ov005Config { char opaque[0x68]; u8 resultCode; } Ov005Config;
extern Ov005Context *data_ov005_0205b80c;
extern Ov005Config data_ov005_0205b85c;
extern void Ov005_StartStatusTween(int);
void Ov005_WaitForMenuEntry(void) {
    Ov005Context *context=data_ov005_0205b80c;
    Ov005Config *config=&data_ov005_0205b85c;
    if(context->menuEntryReady==0)return;
    if(config->resultCode>1 && context->rowItemCounts[0]>0) {
        context->menuState=2;
        data_ov005_0205b80c->statusStep=1;
        Ov005_StartStatusTween(data_ov005_0205b80c->statusStep);
    } else context->menuState=3;
}
