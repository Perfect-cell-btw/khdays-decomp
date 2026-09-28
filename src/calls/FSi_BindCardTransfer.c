#pragma thumb on
/* Switch the active card-transfer id. When the id is unchanged, just re-arm the current slot at
 * +0x98. Otherwise store the new id, wait for the card thread to go idle, re-arm the previous
 * slot at +0x94, bind the id to the list, and allocate a new current slot.
 *
 * Parked as an address-CSE tie -- the original recomputes `obj+0x9c` in each branch (in THUMB
 * that is two instructions, since 0x9c is past the scaled ldr offset) while mwcc hoisted it into
 * a callee-saved register. Reaching the fields through a STRUCT is what reproduces it: each
 * `obj->uId` is its own address computation, where a single `*(unsigned int *)(obj + 0x9c)`
 * expression is one value mwcc is free to keep. */
extern void NNS_SndHeapLoadState(int *list, int value);
extern long long FSi_WaitForCardThread(void);
extern void SoundMgr_WaitLoaderIfState1(long long tick);
extern void NNS_SndArcLoadSeqArc(unsigned int id, int *list);
extern int NNS_SndHeapSaveState(int *list);

struct CardCtx {
    char _pad0[0x94];
    int nPrevSlot;              /* +0x94 */
    int nCurSlot;               /* +0x98 */
    unsigned int uId;           /* +0x9c */
    char _pada0[0xb04a0 - 0xa0];
    int *pList;                 /* +0xb04a0 */
};

extern struct CardCtx *data_0204c234;

void FSi_BindCardTransfer(unsigned int id) {
    struct CardCtx *obj = data_0204c234;

    if (obj->uId == id) {
        NNS_SndHeapLoadState(obj->pList, obj->nCurSlot);
        return;
    }
    obj->uId = id;
    SoundMgr_WaitLoaderIfState1(FSi_WaitForCardThread());
    NNS_SndHeapLoadState(obj->pList, obj->nPrevSlot);
    NNS_SndArcLoadSeqArc(id, obj->pList);
    obj->nCurSlot = NNS_SndHeapSaveState(obj->pList);
}
