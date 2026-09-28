/* Create the 0xc-byte object at data_ov002_0207f62c once, seeding it from the
 * two-word template at data_ov002_0207e358. Already-created is the common case
 * and does nothing -- but the template is copied to the stack BEFORE the check,
 * because it is an ordinary initialised local. */
typedef struct {
    int nFirst;
    int nSecond;
} Ov002SeedTemplate;

extern void *NNSi_FndAllocFromDefaultExpHeap(unsigned int size);
extern void Ov002_CloneBlitDesc(void *obj, const Ov002SeedTemplate *seed);
extern void Ov002_ClearPlayerFlagRecords(void);

extern Ov002SeedTemplate data_ov002_0207e358;
extern void *data_ov002_0207f62c;

void Ov002_CreateSeededObjectOnce(void) {
    Ov002SeedTemplate seed = data_ov002_0207e358;

    if (data_ov002_0207f62c == 0) {
        void *obj = NNSi_FndAllocFromDefaultExpHeap(0xc);

        data_ov002_0207f62c = obj;
        Ov002_CloneBlitDesc(obj, &seed);
        Ov002_ClearPlayerFlagRecords();
    }
}
