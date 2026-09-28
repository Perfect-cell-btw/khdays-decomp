/* Touch handler: picks "yes" in the exit dialog and plays the confirm sound. */

typedef struct Ov005Context {
    char opaque00[0x4bf0];
    int menuState;
    char opaque4bf4[0x1c];
    unsigned char dialogChoice;
} Ov005Context;
extern Ov005Context *data_ov005_0205b80c;
extern void Ov005_RefreshDialogChoice(void);
extern void PlaySound(unsigned int,unsigned int);
void Ov005_ConfirmExitFromTouch(void) {
    if(data_ov005_0205b80c->menuState>=6)return;
    data_ov005_0205b80c->dialogChoice=1;
    Ov005_RefreshDialogChoice();
    data_ov005_0205b80c->menuState=6;
    PlaySound(0,1);
}
