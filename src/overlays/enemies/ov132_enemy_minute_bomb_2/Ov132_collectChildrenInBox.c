/* Collects up to four objects near the box: for every child region not flagged 0x2000, runs the
 * quad-tree sphere query over it; returns how many were found. */

extern int Ov132_collectObjectsInSphereRec(int *pair, int a, int b, int c, int *box2, int *box, int *counter, int p3);
int Ov132_collectChildrenInBox(int param_1, int *param_2, int param_3) {
    int f[7];   /* f[0..1]=pair, f[2]=counter, f[3..6]=box */
    int i;
    f[2] = 0;
    f[3] = param_2[0] - param_2[3];
    f[4] = param_2[2] - param_2[3];
    f[5] = param_2[0] + param_2[3];
    f[6] = param_2[2] + param_2[3];
    for (i = 0; i < (int)(unsigned short)*(unsigned short *)(param_1 + 2); i++) {
        int child = ((int *)*(int *)(param_1 + 4))[i];
        if ((*(unsigned short *)(child + 0x74) & 0x2000) == 0) {
            f[0] = *(int *)(child + 0x84);
            f[1] = *(int *)(child + 0x88);
            Ov132_collectObjectsInSphereRec(&f[0], *(int *)(child + 0x8c), *(int *)(child + 0x9c),
                                *(int *)(child + 0xa4), param_2, &f[3], &f[2], param_3);
            if (f[2] >= 4) break;
        }
    }
    return f[2];
}
