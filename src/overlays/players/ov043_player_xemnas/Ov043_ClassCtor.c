#include "nitro/types.h"

typedef void *(*VoiceEntryFn)(void);

extern void *NNSi_FndGetCurrentRootHeap(void);
extern void Ov043_Construct(void *pObj);
extern void Ov043_ResetScriptRequest(void *root);
extern void Ov043_OpenMissionBlock(void *root);
extern void Ov022_RequestVoiceIds(void *pActor, short nId, u16 nArg2);
extern void *Ov022_ArmDecoder(void);

/* Initialize the voice decoder for pObj, then hand back the entry point
 * (Ov022_ArmDecoder) without calling it -- the caller invokes it later. */
VoiceEntryFn Ov043_ClassCtor(void *pObj) {
    void *root = NNSi_FndGetCurrentRootHeap();

    Ov043_Construct(pObj);
    Ov043_ResetScriptRequest(root);
    Ov043_OpenMissionBlock(root);
    Ov022_RequestVoiceIds(root, 0x4f, 0xc4);

    return (VoiceEntryFn)Ov022_ArmDecoder;
}
