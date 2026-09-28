/* Exit dialog input: moves between yes and no, cancels, or confirms (starting the exit
 * synchronisation in a session, or leaving at once). */

typedef unsigned short u16;
typedef struct MenuLimitHeader { u16 inputMask; short limits[2]; char opaque[20]; } MenuLimitHeader;
typedef struct Ov005Context {
    char opaque00[0x4bf0];
    int menuState;
    char opaque4bf4[0x1c];
    unsigned char dialogChoice,unknown4c11;
    MenuLimitHeader menuLimitHeader;
    char opaque4c2c[0x5d568];
    void *exitTaskHandle;
} Ov005Context;
extern Ov005Context *data_ov005_0205b80c;
extern u16 data_0204c190;
extern const char data_ov005_0205b7cc[];
extern u16 Mem_ReadU16(MenuLimitHeader *);
extern void Ov005_RefreshDialogChoice(void),Ov005_UpdateDialogVisibility(void);
extern void PlaySound(int,int);
extern int Session_IsActive(void);
extern void *InstantiateClass(const void *,void *);
void Ov005_UpdateConfirmation(void) {
    int action;
    u16 held;
    /* The original leaves r4 unchanged if none of these input bits is set. */
    if(Mem_ReadU16(&data_ov005_0205b80c->menuLimitHeader)&0x20)action=0x20;
    if(Mem_ReadU16(&data_ov005_0205b80c->menuLimitHeader)&0x10)action=0x10;
    held=data_0204c190;
    if(held&1)action=1;
    if(held&2)action=2;
    switch(action) {
    case 0x20:
        if(data_ov005_0205b80c->dialogChoice==0) {
            data_ov005_0205b80c->dialogChoice=1;
            Ov005_RefreshDialogChoice();
            PlaySound(0,0);
        }
        break;
    case 0x10:
        if(data_ov005_0205b80c->dialogChoice==1) {
            data_ov005_0205b80c->dialogChoice=0;
            Ov005_RefreshDialogChoice();
            PlaySound(0,0);
        }
        break;
    case 1:
        if(data_ov005_0205b80c->dialogChoice==0) {
            data_ov005_0205b80c->menuState=3;
            Ov005_UpdateDialogVisibility();
            data_ov005_0205b80c->dialogChoice=0;
            PlaySound(0,3);
        } else {
            if(Session_IsActive()) {
                data_ov005_0205b80c->exitTaskHandle=InstantiateClass(data_ov005_0205b7cc,0);
                data_ov005_0205b80c->menuState=5;
            } else data_ov005_0205b80c->menuState=6;
            PlaySound(0,1);
        }
        break;
    case 2:
        data_ov005_0205b80c->menuState=3;
        Ov005_UpdateDialogVisibility();
        data_ov005_0205b80c->dialogChoice=0;
        PlaySound(0,3);
        break;
    }
}
