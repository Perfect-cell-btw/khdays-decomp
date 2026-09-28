/* When the instance is marked dead (-2), releases it (if still live); returns whether it was dead.
 */

extern void func_02023ad0(int *arg);

int Instance_ReleaseIfDead(int *p) {
    int result = 0;
    if (p[5] == -2) {
        if (p[0] & 1) func_02023ad0(p);
        result = 1;
    }
    return result;
}
