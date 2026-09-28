/* Character constructor: builds the panel object, initialises its effect record, requests its two
 * voice ids and returns the decoder step. */

extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov102_PanelCtor(int a);
extern void Ov102_InitTwoGlobalRegionsAndForward(int a);
extern void Ov022_RequestVoiceIds(int a, int b, int c);
extern void Ov022_ArmDecoder(void);
void *Ov102_stateCtorReturnHandler(int param) {
    int obj = NNSi_FndGetCurrentRootHeap();
    Ov102_PanelCtor(param);
    Ov102_InitTwoGlobalRegionsAndForward(obj);
    Ov022_RequestVoiceIds(obj, 0x52, 0xd4);
    return (void *)Ov022_ArmDecoder;
}
