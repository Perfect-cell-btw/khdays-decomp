/* * TWO arity bugs in one function, and the old header blamed both on the compiler:
 * "register-spill tie -- the ROM reserves a stack slot and spills the duration temp across the
 * setup (160B), our mwcc keeps it in registers (136B). Not steerable from C."
 * The reserved stack slot was the 5th ARGUMENT.
 *   - Ov006_RequestMenuState itself takes THREE params. The ROM's `str r2, [sp]` saves the incoming
 *     r2 BEFORE `mov r2, #0` overwrites it -- so param_3 is forwarded as 020551a4's 5th argument.
 *   - Ov006_MissionRequestStateChange takes FIVE args (the 5th on the stack), not four.
 * SKILL.md's phantom-args table already listed both. (2026-07-17)
 *
 * `dur` is an unsigned short: the ROM's `lsl #0x10 ; lsr #0x10` truncates it before the call.
 * The ternary is written `!= 0 ? 1000 : 0` so the ne-value is the true branch, matching the ROM's
 * `movne #0x3e8 ; moveq #0` order (codegen-cracks.md).
 */
/* Ov006_RequestMenuState -- request a Mission Mode-screen menu-state transition to state param_1.
 * Duration: 0 if param_2==0, else 1000, but forced to 1 when transitioning to a non-blank state
 * while the current state (ctx+0x94f4) is 0xe. Kicks Ov006_MissionRequestStateChange; on the blank state
 * (10) also clears ctx+0x956c and resets the shared tween (ctx+0x9544). Returns 0 if no ctx. */
extern void Ov006_MissionRequestStateChange(unsigned int state, int dur, int sfxA, int sfxB, int e);
extern void Tween_Clear(unsigned int *interp);
extern int  data_ov006_02056664;   /* -> Mission Mode-screen context */

int Ov006_RequestMenuState(unsigned int param_1, int param_2, int param_3) {
    unsigned short dur;
    if (data_ov006_02056664 == 0) {
        return 0;
    }
    dur = (param_2 != 0) ? 1000 : 0;
    if (param_1 != 10 && *(int *)(data_ov006_02056664 + 0x94f4) == 0xe) {
        dur = 1;
    }
    Ov006_MissionRequestStateChange(param_1, dur, 0, -0x10, param_3);
    if (param_1 == 10) {
        *(int *)(data_ov006_02056664 + 0x956c) = 0;
        Tween_Clear((unsigned int *)(data_ov006_02056664 + 0x9544));
    }
    return 1;
}
