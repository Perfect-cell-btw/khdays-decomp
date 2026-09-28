/*
 * Ov008_EnableBothHalves -- x3 (ov008/...). Enable or disable both half-screens together.
 * Context at data_02090f04[1]+0x9000. Each half is "on" only when `enable` is set and its own ready
 * flag (+0x9600 / +0x9604) is non-zero. Push that on/off state into the two command lists at +0x9500
 * and +0x954c (02055c08), publish their +0x20 halfwords (02055c40), and set control bits 1 and 0 of
 * the +0xa7c word for each surface (02054e4c / 02054e24; the second surface base is +0x4a80).
 *
 * All context reads use CTXV (volatile): the retail compiler re-loads data_02090f04[1] for every
 * access; mwcc 3.0/139 would cache it. The volatile forces the reload; behaviour is identical.
 */
extern void Ov008_SetFlagBit0(int cmdlist, int on);
extern void Ov008_SetHalfword20(int cmdlist);
extern void Ov008_SetControlBit1AtA7C(int surface, int on);
extern void Ov008_SetControlBit0AtA7C(int surface, int on);
extern int data_ov008_02090f04[];

#define CTXV (*(volatile int *)((char *)data_ov008_02090f04 + 4))

void Ov008_EnableBothHalves(int enable) {
    int u1 = (enable != 0 && *(int *)(CTXV + 0x9600) != 0);
    int u2 = (enable != 0 && *(int *)(CTXV + 0x9604) != 0);

    Ov008_SetFlagBit0(CTXV + 0x9500, u1);
    Ov008_SetFlagBit0(CTXV + 0x954c, u2);
    Ov008_SetHalfword20(CTXV + 0x9500);
    Ov008_SetHalfword20(CTXV + 0x954c);
    Ov008_SetControlBit1AtA7C(CTXV, u1);
    Ov008_SetControlBit1AtA7C(CTXV + 0x4a80, u2);
    Ov008_SetControlBit0AtA7C(CTXV, u1);
    Ov008_SetControlBit0AtA7C(CTXV + 0x4a80, u2);
}
