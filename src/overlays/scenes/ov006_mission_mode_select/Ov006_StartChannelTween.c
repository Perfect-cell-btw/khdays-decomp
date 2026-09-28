/* Ov006_StartChannelTween -- start a Mission Mode-screen fade/param tween on channel param_2 (0..3).
 * Interpolator lives at ctx+0x9684 + param_2*0x1c; runs from 0 to param_1<<12 (Q12) over param_3.
 * Returns 0 if the context is not up or the channel is out of range, else 1. */
extern void Tween_Configure(unsigned int *interp, int mode, unsigned int from, unsigned int to, unsigned int dur);
extern void Tween_Start(unsigned int *interp);
extern int  data_ov006_02056664;   /* -> Mission Mode-screen context */

int Ov006_StartChannelTween(int param_1, unsigned int param_2, unsigned int param_3) {
    if (data_ov006_02056664 == 0) {
        return 0;
    }
    if (param_2 <= 3) {
        Tween_Configure((unsigned int *)(data_ov006_02056664 + 0x9684 + param_2 * 0x1c), 2, 0,
                      param_1 << 0xc, param_3);
        Tween_Start((unsigned int *)(data_ov006_02056664 + 0x9684 + param_2 * 0x1c));
        return 1;
    }
    return 0;
}
