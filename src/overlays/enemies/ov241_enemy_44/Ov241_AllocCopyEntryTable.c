/* Replaces the object's entry table (0x14 bytes each) with a copy of the source table and its two
 * values. */

typedef struct {
    int word0;
    int word1;
    int count;
    char data[0];
} Header241;

typedef struct {
    char pad[0x3a4];
    void *data;
    int count;
    char pad_3ac[8];
    int word0;
    int word1;
} Obj241;

extern void FreeInstanceMemory(void *ptr);
extern void *CallocInstance(int size);
extern void MI_CpuCopy8(void *src, void *dst, int size);

void Ov241_AllocCopyEntryTable(Obj241 *obj, int unused, Header241 *src)
{
    if (obj->data != 0) {
        FreeInstanceMemory(obj->data);
        obj->data = 0;
    }

    obj->data = CallocInstance(src->count * 0x14);
    MI_CpuCopy8(src->data, obj->data, src->count * 0x14);
    obj->count = src->count;
    obj->word0 = src->word0;
    obj->word1 = src->word1;
}
