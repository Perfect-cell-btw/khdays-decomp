/* Class pfnCtor: constructs the object, resets and inits it, requests voice ids 0x4f/0xc4 and
 * returns the decoder step. */

extern void *NNSi_FndGetCurrentRootHeap(void);
extern void Ov062_Construct(void *arg0);
extern void Ov062_ResetScriptRequest(void *heap);
extern void Ov062_OpenMissionBlock(void *heap);
extern void Ov022_RequestVoiceIds(void *heap, int nId, int nArg2);
extern void *Ov022_ArmDecoder(void);

void *Ov062_ClassCtor(void *arg0) {
    void *heap = NNSi_FndGetCurrentRootHeap();
    Ov062_Construct(arg0);
    Ov062_ResetScriptRequest(heap);
    Ov062_OpenMissionBlock(heap);
    Ov022_RequestVoiceIds(heap, 0x4f, 0xc4);
    return Ov022_ArmDecoder;
}
