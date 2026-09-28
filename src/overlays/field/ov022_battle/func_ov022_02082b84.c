/* Tears the battle scene down: releases the service instances and slot objects, retires pending
 * slot entries, pops the VRAM state, tears the context down and disables the sound listeners. */

extern void func_ov022_020831dc(void);
extern void Ov002_ReleaseAllSlotObjects(void);
extern void Ov002_RetirePendingSlotEntries(void);
extern void EntityMgr_PopVramState(void);
extern void Ov002_TearDownContext(void);
extern void SoundMgr_SetListenersEnabled(int arg0);
extern int data_ov022_020b2e60;

void func_ov022_02082b84(void) {
    func_ov022_020831dc();
    Ov002_ReleaseAllSlotObjects();
    Ov002_RetirePendingSlotEntries();
    EntityMgr_PopVramState();
    Ov002_TearDownContext();
    SoundMgr_SetListenersEnabled(0);
    ((int *)&data_ov022_020b2e60)[1] = 0;
    ((int *)&data_ov022_020b2e60)[0] = 0;
}
