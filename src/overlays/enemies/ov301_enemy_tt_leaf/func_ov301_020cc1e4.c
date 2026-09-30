/* Detaches the actor from its region through the shared enemy framework
 * (Ov107_Actor_DetachFromRegion), passing every argument through. */

extern int Ov107_Actor_DetachFromRegion();

int func_ov301_020cc1e4(int a, int b, int c, int d) {
    return Ov107_Actor_DetachFromRegion(a, b, c, d);
}
