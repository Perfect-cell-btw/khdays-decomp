/* Ov106_SubSceneTick -- per-frame tick of the ov023 sub-scene: run the active slot's handler,
 * where the active index is the global at data_0204be04 and the slots are 4 bytes apart at +0x60
 * of the context. Always reports 0. */
extern void Ov106_DrawNoiseOverlay(int obj);
extern unsigned char data_0204be04;
extern int data_ov106_020b8b68;

int Ov106_SubSceneTick(void) {
    int obj = *(int *)(*(int *)&data_ov106_020b8b68 + data_0204be04 * 4 + 0x60);
    if (obj != 0) {
        Ov106_DrawNoiseOverlay(obj);
    }
    return 0;
}
