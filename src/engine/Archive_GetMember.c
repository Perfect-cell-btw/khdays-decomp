/* Two-level archive lookup: take the table pointer for `member`, then the entry for `index` within
 * it, or null when the member table is absent. Ov002_LoadBackgroundSet uses members 0, 1 and 6 for
 * a background's palette, character data and screen map. */

int Archive_GetMember(void *pR0, int r1, int r2)
{
    int *r0 = (int *)pR0;
    int *p = ((int **)(r0 + r1))[2];
    return p ? ((int **)(p + r2))[1] : 0;
}
