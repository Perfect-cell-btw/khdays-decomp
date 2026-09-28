typedef struct Ov005Context {
    char opaque00[0x4bf0];
    int menuState;
    char opaque4bf4[0x1c];
    unsigned char dialogChoice;
} Ov005Context;
extern Ov005Context *data_ov005_0205b80c;
extern void Ov005_RefreshDialogChoice(void),Ov005_UpdateDialogVisibility(void);
extern void PlaySound(unsigned int,unsigned int);
void Ov005_CancelExitFromTouch(void) {
    if(data_ov005_0205b80c->menuState>=6)return;
    data_ov005_0205b80c->dialogChoice=0;
    Ov005_RefreshDialogChoice();
    data_ov005_0205b80c->menuState=3;
    Ov005_UpdateDialogVisibility();
    data_ov005_0205b80c->dialogChoice=0;
    PlaySound(0,3);
}
