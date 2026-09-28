/* Ov008_StartWipeToSubState -- start a horizontal wipe to a new Mission Mode sub-state, ov006.
 * If the Mission Mode object exists, kicks a scroll animation on the Mission Mode layer (base+0x9544) from
 * x=-0x10000 to 0 over 600 units, commits it (Tween_Start), and latches the pending sub-state
 * id (base+0x94f4 = arg). Returns 1 when started, 0 if there is no Mission Mode object. */
extern void Tween_Configure(unsigned int *anim, int a, int from, int to, int dur);
extern void Tween_Start(int anim);
extern int  data_ov008_02090fa4;

int Ov008_StartWipeToSubState(int state) {
    if (data_ov008_02090fa4 != 0) {
        Tween_Configure((unsigned int *)(data_ov008_02090fa4 + 0x9544), 0, -0x10000, 0, 600);
        Tween_Start(data_ov008_02090fa4 + 0x9544);
        *(int *)(data_ov008_02090fa4 + 0x94f4) = state;
        return 1;
    }
    return 0;
}
