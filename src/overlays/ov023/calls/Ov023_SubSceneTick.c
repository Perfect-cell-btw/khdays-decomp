/* Ov023_SubSceneTick -- per-frame tick of the ov023 sub-scene: run the active slot's handler,
 * where the active index is the global at data_0204be04 and the slots are 4 bytes apart at +0x60
 * of the context. Always reports 0. */
extern void Ov023_DrawNoiseOverlay(int obj);
extern unsigned char data_0204be04;
extern int data_ov023_0208a7c0;

int Ov023_SubSceneTick(void) {
    int obj = *(int *)(*(int *)&data_ov023_0208a7c0 + data_0204be04 * 4 + 0x60);
    if (obj != 0) {
        Ov023_DrawNoiseOverlay(obj);
    }
    return 0;
}
