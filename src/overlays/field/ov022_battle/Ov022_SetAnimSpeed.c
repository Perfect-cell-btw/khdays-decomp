/* Sets the actor's animation speed (+0x458; 0x1000 is normal, and bit 6 of its node flags marks
 * any other) and its animation step (+0x2aba): the frame time (Ov022_GetGlobal34) times the
 * speed, which Ov022_StepScaledAnimTracks hands to Sequence_UpdateTracks. */

extern int Ov022_GetGlobal34(void);
extern int FX_Div(int actor, int speed);

void Ov022_SetAnimSpeed(int actor, int speed) {
    volatile unsigned int *p = *(unsigned int **)(actor + 0x20);
    int inv;
    *p = (speed != 0x1000) ? (*p | 0x40) : (*p & ~0x40);
    inv = FX_Div(Ov022_GetGlobal34(), 0x1000);
    *(int *)(actor + 0x458) = speed;
    *(short *)(actor + 0x2aba) = (short)(((long long)inv * speed + 0x800) >> 0xc);
}
