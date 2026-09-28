/* Runs the actor's reach handlers; returns 2 when a flagged reach succeeded, 1 for a plain one, 0
 * otherwise. */

extern int Ov022_RunReachHandlers(unsigned int *arg0, int *arg1, unsigned int *arg2);
int Ov022_TrySpawnAction(int arg0, int *arg1, unsigned int *arg2) {
    unsigned int *p = *(unsigned int **)(arg0 + 0x58);
    int r = 0;
    if (Ov022_RunReachHandlers(p, arg1, arg2) != 0) {
        unsigned int f = p[0x9af];
        if (f & 1) r = 2;
        else if (f & 4) r = 2;
        else r = 1;
    }
    return r;
}
