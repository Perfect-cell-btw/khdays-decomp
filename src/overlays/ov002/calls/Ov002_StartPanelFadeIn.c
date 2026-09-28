/* Start the panel's fade tween at +0xf8: mode 1, from 0 to full (0x18000) over
 * 300 frames, then sample it once so the first frame is already correct. */
extern void Tween_Configure(void *tween, int mode, int from, int to, int duration);
extern void Tween_Start(void *tween);

extern char *data_ov002_0207f614;

void Ov002_StartPanelFadeIn(void) {
    char *ctx = data_ov002_0207f614;

    Tween_Configure(ctx + 0xf8, 1, 0, 0x18000, 300);
    Tween_Start(ctx + 0xf8);
}
