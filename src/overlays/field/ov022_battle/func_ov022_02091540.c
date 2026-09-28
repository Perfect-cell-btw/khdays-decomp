/* Advances an animation when it has at least the step left; returns whether it ended. */

extern int Anim_GetLengthQ12(unsigned short *p, unsigned int idx);
extern unsigned int Sequence_UpdateTracks(unsigned short *p, int param_2);

unsigned int func_ov022_02091540(unsigned short *param_1, int param_2) {
    int iVar1 = 0;
    unsigned int uVar2 = 0;
    unsigned int uVar3 = 1;
    do {
        if (((int *)param_1)[uVar2 + 3] != 0 && ((short *)param_1)[uVar2 + 1] >= 0) {
            iVar1 = Anim_GetLengthQ12(param_1, uVar2 & 0xffff);
            goto done;
        }
        uVar2 = uVar2 + 1;
    } while ((int)uVar2 < 5);
done:
    if (iVar1 >= param_2) {
        uVar3 = Sequence_UpdateTracks(param_1, param_2);
    }
    return uVar3 & 0xffff;
}
