extern int GetTrackEntryBase();
extern unsigned char *FindEntryByExactName();
void StoreValueInNamedEntry(int param_1, unsigned char *param_2, int *param_3)
{
    int t = GetTrackEntryBase(param_1);
    int i = 0;
    if ((int)*(unsigned short *)(t + 2) <= 0)
        return;
    while (1) {
        int e = ((int *)*(int *)(t + 4))[i];
        if (e != 0) {
            unsigned char *found = FindEntryByExactName(e, param_2);
            if (found != 0) {
                *(int *)(found + 0xc) = *param_3;
                return;
            }
        }
        i++;
        if ((int)(unsigned int)*(unsigned short *)(t + 2) <= i)
            return;
    }
}
