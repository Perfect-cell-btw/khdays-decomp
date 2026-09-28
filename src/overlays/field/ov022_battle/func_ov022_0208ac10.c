/* Runs the actor's command handlers; returns 2 for a flagged command, 1 for a plain one (0 when a
 * guarded target is not the special kind 0x6b). */

extern int Ov022_RunCommandHandlers(unsigned int *a, int *b, unsigned int *c);

int func_ov022_0208ac10(int param_1, int *param_2, unsigned int *param_3) {
    unsigned int *p = *(unsigned int **)(param_1 + 0x58);
    int r = 0;
    if (Ov022_RunCommandHandlers(p, param_2, param_3) == 0) {
        goto done;
    }
    if (p[0x9af] & 1) {
        r = 2;
        goto done;
    }
    if (p[0x9af] & 4) {
        r = 2;
        goto done;
    }
    r = 1;
    if (*(unsigned char *)(p + 0x9b1) != 1) {
        goto done;
    }
    {
        int rp = p[0x9b5];
        if ((*(unsigned short *)(rp + 0x1ac) & 4) &&
            *(unsigned char *)(rp + 0x19c) != 0x6b) {
            r = 0;
        }
    }
done:
    return r;
}
