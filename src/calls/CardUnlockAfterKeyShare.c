/* End wireless key sharing if it is still up (the two Text_VSNPrintf helpers), then release the
 * card resource with CARDi_UnlockResource(resource, 2). */

extern int CARD_TryWaitRomAsync(void);
extern void CARD_WaitRomAsync(void);
extern void CARDi_UnlockResource(int resource, int kind);

void CardUnlockAfterKeyShare(int resource) {
    if (CARD_TryWaitRomAsync() == 0)
        CARD_WaitRomAsync();
    CARDi_UnlockResource(resource, 2);
}
