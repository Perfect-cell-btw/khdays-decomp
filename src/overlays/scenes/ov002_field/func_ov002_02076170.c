typedef struct {
    char pad00[4];
    char *pContext;                 /* +0x04 */
} Ov002SceneRef;

extern Ov002SceneRef data_ov002_0207fa20;

extern void ClearGlobalArrayInt(int nMode);
extern void Ov002_RetireAllListEntries(void);
extern void ZeroHalfThenFree(int pObject);
extern void StoreGlobalArrayEntry(int nId, int nFlags);
extern void UnloadOverlaySync(int nKind, int nHandle);

/* Tear down the scene: stop the sub-object it owns, release the reserved slot
 * if one is held, and drop the context reference. */
void func_ov002_02076170(void)
{
    ClearGlobalArrayInt(5);
    Ov002_RetireAllListEntries();

    if (*(int *)(data_ov002_0207fa20.pContext + 0x60) != 0) {
        ZeroHalfThenFree(*(int *)(data_ov002_0207fa20.pContext + 0x60));
        *(int *)(data_ov002_0207fa20.pContext + 0x60) = 0;
    }

    if (*(signed char *)(data_ov002_0207fa20.pContext + 0x260) != -1) {
        StoreGlobalArrayEntry(*(signed char *)(data_ov002_0207fa20.pContext + 0x260) + 5, 0);
        UnloadOverlaySync(0, *(int *)(data_ov002_0207fa20.pContext + 0x264));
        *(signed char *)(data_ov002_0207fa20.pContext + 0x260) = -1;
    }

    data_ov002_0207fa20.pContext = 0;
}
