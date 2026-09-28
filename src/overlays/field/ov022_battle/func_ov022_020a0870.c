extern short Session_GetLocalPlayerIndex(void);
extern unsigned int Ov022_ActorSetState(unsigned int *arg0, int arg1);
unsigned int func_ov022_020a0870(unsigned int *arg0, int arg1) {
    unsigned int r = 0;
    if (Session_GetLocalPlayerIndex() == 0) {
        r = Ov022_ActorSetState(arg0, arg1);
        arg0[0x118] = r;
    }
    return r;
}
