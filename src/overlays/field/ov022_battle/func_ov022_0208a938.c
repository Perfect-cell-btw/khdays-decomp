/* Sets the frame of all five animation tracks. */

extern void Anim_SetFrameWrapped(unsigned short *arg0, int arg1, int arg2);
void func_ov022_0208a938(unsigned short *arg0, int arg1) {
    unsigned int i = 0;
    do {
        Anim_SetFrameWrapped(arg0, i & 0xffff, arg1);
        i++;
    } while ((int)i < 5);
}
