/* Retarget the scene's tween at +0x58 to the caller's range over 50 frames and
 * sample it immediately. The context is the SECOND word at data_ov002_0207f62c. */
extern void Tween_Configure(void *tween, int mode, int from, int to, int duration);
extern void Tween_Start(void *tween);

extern char *data_ov002_0207f62c;

void Ov002_RetargetSceneTween(int from, int to) {
    char *ctx = (&data_ov002_0207f62c)[1];

    Tween_Configure(ctx + 0x58, 0, from, to, 50);
    Tween_Start(ctx + 0x58);
}
