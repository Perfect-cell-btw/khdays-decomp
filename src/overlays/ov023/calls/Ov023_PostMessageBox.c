/* Ov023_PostMessageBox -- post a message box on the ov023 scene's dialogue object.
 * The object sits at +0x87564 of the scene root (data_ov023_0208a784[1]). Tween_Configure takes the
 * two caller-supplied parameters plus a fixed style 0x32 as its fifth (stack) argument; the object
 * is then committed with Tween_Start. */
extern void Tween_Configure(int obj, int a, int b, int c, int d);
extern void Tween_Start(int obj);
extern int data_ov023_0208a784;

void Ov023_PostMessageBox(int a, int b) {
    Tween_Configure(*(int *)((char *)&data_ov023_0208a784 + 4) + 0x87564, 0, a, b, 0x32);
    Tween_Start(*(int *)((char *)&data_ov023_0208a784 + 4) + 0x87564);
}
