typedef struct Ov005Context {
    char opaque00[0x4bf0];
    int menuState;
    char opaque4bf4[0x5d5a0];
    void *exitTaskHandle;
} Ov005Context;
extern Ov005Context *data_ov005_0205b80c;
extern void Ov005_UpdateDialogVisibility(void);
extern int Ov005_IsSubContextUsable(void);
extern void func_02023ad0(void *);
void Ov005_WaitForExitTask(void) {
    Ov005_UpdateDialogVisibility();
    if(Ov005_IsSubContextUsable()==0)return;
    func_02023ad0(data_ov005_0205b80c->exitTaskHandle);
    data_ov005_0205b80c->exitTaskHandle=0;
    data_ov005_0205b80c->menuState=6;
}
