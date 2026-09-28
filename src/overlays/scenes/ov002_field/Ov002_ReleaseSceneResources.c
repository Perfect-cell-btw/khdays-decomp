extern void Render_ReleaseNodeItem(int pSub);
extern void Loader_SleepIfBusy(void);
extern void SoundBank_Release(int nA, int nB);
extern void func_020235bc(int nId);

/* Tear down the scene's transient state: stop the sub-object when its owner
 * still has one, then release the two resources flagged in the state byte. */
void Ov002_ReleaseSceneResources(int pScene)
{
    if (*(signed char *)(*(int *)(pScene + 8) + 0x58) != 0) {
        Render_ReleaseNodeItem(pScene + 0x2c);
    }

    if ((*(unsigned char *)(pScene + 0x1b5) & 4) != 0) {
        Loader_SleepIfBusy();
        SoundBank_Release(-1, 0x2be);
        *(unsigned char *)(pScene + 0x1b5) &= ~4;

        if ((*(unsigned char *)(pScene + 0x1b5) & 0x10) != 0) {
            *(unsigned char *)(pScene + 0x1b5) &= ~0x10;
            func_020235bc(0x20e0);
        }
    }
}
