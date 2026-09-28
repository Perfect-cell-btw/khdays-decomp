/* Copies data into the entity manager's track-data pool and attaches it to the first track entry
 * with the given name. */

extern void MI_CpuCopy8(const void *src, void *dst, unsigned int size);
extern void *FindEntryByExactName(void *pTable, const char *pName);

typedef struct {
    unsigned short pad0;
    unsigned short count;
    void **entries;
} S5;

extern S5 *GetTrackEntryBase(int nTrack);

extern unsigned char *data_0204c208;

void EntityMgr_AttachTrackData(unsigned int nTrack, const char *pName, const void *src, unsigned int size) {
    S5 *s;
    int i;
    void *entry;
    unsigned int off;
    unsigned char *dst;

    s = GetTrackEntryBase(nTrack);
    i = 0;
    if ((int)s->count <= 0) {
        return;
    }
    do {
        if (s->entries[i] != 0) {
            entry = FindEntryByExactName(s->entries[i], pName);
            if (entry != 0) {
                off = *(unsigned int *)(data_0204c208 + 0xa1cc);
                dst = data_0204c208 + 0x61cc + off;
                *(unsigned int *)(data_0204c208 + 0xa1cc) = off + size;
                MI_CpuCopy8(src, dst, size);
                *(void **)((unsigned char *)entry + 0x10) = dst;
                return;
            }
        }
        i++;
    } while (i < (int)s->count);
}
