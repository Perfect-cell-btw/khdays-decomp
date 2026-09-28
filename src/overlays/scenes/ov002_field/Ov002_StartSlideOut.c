/* Slide the scene out, if it is allowed to.
 *
 * The tween runs from zero to minus one screen width over fifty frames, and the scene moves to
 * phase 3 once it is running. Nothing happens at all when the check refuses.
 *
 * The tween address is written as the context plus 0x58 at both call sites rather than held in a
 * local, which is what makes the original form it twice.
 */

extern char *data_ov002_0207f62c[];
extern int Ov002_ElementList_IsEmpty(void);
extern void Tween_Configure(void *tween, int from, int to, int flags, int frames);
extern void Tween_Start(void *tween);

void Ov002_StartSlideOut(void) {
    char *ctx = data_ov002_0207f62c[1];

    if (Ov002_ElementList_IsEmpty()) {
        Tween_Configure(ctx + 0x58, 0, -0x10000, 0, 0x32);
        Tween_Start(ctx + 0x58);
        *(int *)(ctx + 8) = 3;
    }
}
