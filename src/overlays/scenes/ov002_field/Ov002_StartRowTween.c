/* Record the row's target at +0x1204 and start that row's 0x1c-byte tween at
 * +0x11b0 running to 0x64000 over 1000 frames, sampling it once. */
extern void Tween_Configure(void *tween, int mode, int from, int to, int duration);
extern void Tween_Start(void *tween);

extern char *data_ov002_0207f628;

void Ov002_StartRowTween(int row, int target) {
    char *ctx = data_ov002_0207f628;
    char *tween;

    *(int *)(ctx + row * 4 + 0x1204) = target;
    tween = ctx + 0x11b0 + row * 0x1c;
    Tween_Configure(tween, 0, 0, 0x64000, 1000);
    Tween_Start(tween);
}
