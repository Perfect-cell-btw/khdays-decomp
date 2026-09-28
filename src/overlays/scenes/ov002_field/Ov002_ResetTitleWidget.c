/* Put the title widget back to its starting state.
 *
 * The widget lives 0x132c into the scene object; it is placed from a language-dependent resource
 * path with an empty three-word box, given its follow-up pass, and then the four words at 0x1464
 * are cleared.
 *
 * The box is written as an initialiser rather than three assignments on purpose: that is what
 * makes the compiler take its address into a register and store through it, where separate
 * assignments give stack-relative stores instead.
 */

extern char *data_ov002_0207f628;
extern char data_ov002_0207ebc4[];
extern char *Msg_BuildLangPath(char *name);
extern void Ov002_PlaceWidget(char *widget, char *path, int *box, int flags, int mode);
extern void Ov002_BindNodeTracks02(char *widget);

void Ov002_ResetTitleWidget(void) {
    char *ctx = data_ov002_0207f628;
    int box[3] = { 0, 0, 0 };
    int i;
    Ov002_PlaceWidget(ctx + 0x132c, Msg_BuildLangPath(data_ov002_0207ebc4), box, 0x20000, 5);
    Ov002_BindNodeTracks02(ctx + 0x132c);
    i = 0;
    do {
        i++;
        *(int *)(ctx + 0x1464) = 0;
        ctx += 4;
    } while (i < 4);
}
