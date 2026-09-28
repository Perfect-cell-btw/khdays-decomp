extern int CARD_TryWaitRomAsync(void);
extern void CARD_WaitRomAsync(void);
extern void CARDi_UnlockResource(int resource, int kind);

void CardUnlockAfterKeyShare(int resource) {
    if (CARD_TryWaitRomAsync() == 0)
        CARD_WaitRomAsync();
    CARDi_UnlockResource(resource, 2);
}
