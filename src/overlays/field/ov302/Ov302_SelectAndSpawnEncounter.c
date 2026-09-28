extern void *Ov302_CreateEncounterRecord(int rec, void *sub);
extern void NNS_FndAppendListObject(void *list, void *obj);

/* Scan the count-prefixed candidate array `param_2` for the best entry whose
 * level window brackets `param_3` (or that starts above it), preferring the
 * lowest window start; if one is found, instantiate it via Ov302_CreateEncounterRecord
 * and append to the list at param_1+0x18. Returns 1 if an entry was appended. */
int Ov302_SelectAndSpawnEncounter(int param_1, unsigned short *param_2, unsigned int param_3) {
    int i;
    int ret;
    unsigned short *best;
    unsigned short *bestsub;
    int count;
    unsigned int stride;

    ret = 0;
    bestsub = 0;
    best = 0;
    i = 0;
    count = *param_2++;
    if (count > 0) {
        do {
            unsigned int v = param_2[3];
            if (((v <= param_3 + 1 && param_3 + 1 <= param_2[4]) || param_3 < v) &&
                (best == 0 || v < best[3])) {
                bestsub = param_2 + 0x18;
                best = param_2;
            }
            stride = *param_2;
            i = i + 1;
            param_2 = (unsigned short *)((char *)param_2 + stride);
        } while (i < count);
    }
    if (best != 0) {
        void *rec = Ov302_CreateEncounterRecord((int)best, bestsub);
        NNS_FndAppendListObject((void *)(param_1 + 0x18), rec);
        ret = 1;
    }
    return ret;
}
