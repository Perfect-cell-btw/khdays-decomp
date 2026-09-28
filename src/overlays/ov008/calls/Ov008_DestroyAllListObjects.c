extern void *NNS_FndGetNextListObject(void *list, void *object);
extern void Ov008_DestroyObject(void *context, void *entry);

typedef struct {
    char pad[0x4a38];
    char list;
} Unk020546ec;

void Ov008_DestroyAllListObjects(void *context)
{
    void *entry = NNS_FndGetNextListObject(&((Unk020546ec *)context)->list, 0);

    if (entry != 0) {
        int offset = 0x4a38;

        do {
            void *next = NNS_FndGetNextListObject((char *)context + offset, entry);

            Ov008_DestroyObject(context, entry);
            entry = next;
        } while (entry != 0);
    }
}
