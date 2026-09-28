/* Sets the frame of all five tracks of one of the actor's effect models. */

extern void Anim_SetFrameWrapped(unsigned short *arg0, int arg1, int arg2);
void func_ov022_0209b0c0(int arg0, int arg1, int arg2) {
    unsigned int i = 0;
    do {
        Anim_SetFrameWrapped((unsigned short *)(arg0 + 0x278c + arg1 * 0x108), i & 0xffff, arg2);
        i++;
    } while ((int)i < 5);
}
