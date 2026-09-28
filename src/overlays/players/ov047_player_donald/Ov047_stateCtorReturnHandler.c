/* Character constructor: builds the panel object, initialises its effect record, requests its two
 * voice ids and returns the decoder step. */

extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov047_PanelCtor(int a);
extern void Ov047_InitTwoGlobalRegionsAndForward(int a);
extern void Ov022_RequestVoiceIds(int a, int b, int c);
extern void Ov022_ArmDecoder(void);
void *Ov047_stateCtorReturnHandler(int param) {
    int obj = NNSi_FndGetCurrentRootHeap();
    Ov047_PanelCtor(param);
    Ov047_InitTwoGlobalRegionsAndForward(obj);
    Ov022_RequestVoiceIds(obj, 0x52, 0xd4);
    return (void *)Ov022_ArmDecoder;
}
