extern void Ov256_Claw_Launch(int target, int param_2);
/* Raise the "done" flag (+0x39c); when the actor is in state 1, forward to
 * the sub-target (+0x214) along with the second argument. */
void Ov256_Claw_LaunchIfReady(int obj, int param_2) {
    *(int *)(obj + 0x39c) = 1;
    if (*(int *)(obj + 0x50) != 1) {
        return;
    }
    Ov256_Claw_Launch(*(int *)(obj + 0x214), param_2);
}
