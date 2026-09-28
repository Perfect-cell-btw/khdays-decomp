extern int Game_PollSceneAlive(void);
extern int Ov105_RunScriptedStepState3(void);
extern void Ov105_WH_Finalize(void);

struct CardXferOwner {
    char _pad[0x49c];
    int nField49c;
};
extern struct CardXferOwner *data_ov006_020565e4;

void Ov006_TickCardTransferScene(void) {
    switch (Game_PollSceneAlive()) {
    case 0:
        return;
    case 1:
        if (Ov105_RunScriptedStepState3() != 0) {
            data_ov006_020565e4->nField49c = 0;
        }
        return;
    case 3:
        return;
    default:
        Ov105_WH_Finalize();
    }
}
