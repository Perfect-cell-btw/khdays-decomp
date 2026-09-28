/* Whether a height is above the actor by more than 1.0 and still within reach. */

extern int func_ov022_020afd38(int arg0, int arg1);
int func_ov022_020afd0c(int arg0, int arg1) {
    if (arg1 - *(int *)(arg0 + 0x490) > 0x1000 && func_ov022_020afd38(arg0, arg1) != 0) return 1;
    return 0;
}
