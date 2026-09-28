/* Initializes the ov077 rig object and scene resources, starts encounter parameters 0x49/0xc8, and
 * returns the next-state function. */

extern void *NNSi_FndGetCurrentRootHeap(void);
extern void Ov077_BuildRigObject(void *obj);
extern void Ov077_InitSceneResources(void *heap);
extern void Ov022_RequestVoiceIds(void *heap, int x, int y);
extern void Ov022_ArmDecoder(void);

int Ov077_InitAndReturnNextState(void *obj) {
    void *h = NNSi_FndGetCurrentRootHeap();
    Ov077_BuildRigObject(obj);
    Ov077_InitSceneResources(h);
    Ov022_RequestVoiceIds(h, 0x49, 0xc8);
    return (int)Ov022_ArmDecoder;
}
