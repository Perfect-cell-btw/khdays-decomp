typedef struct {
    char pad[0x3a0];
    void *data;
    int word0;
    int word1;
} Obj291;

typedef struct {
    int word0;
    int word1;
} Header291;

extern void MI_CpuCopy8(void *src, void *dst, int size);
extern void *CallocInstance(int size);
extern void FreeInstanceMemory(void *ptr);

void Ov291_ReallocBufferCopyHeader(Obj291 *obj, int size, Header291 *src)
{
    void *dst;

    if (obj->data != 0) {
        FreeInstanceMemory(obj->data);
        obj->data = 0;
    }

    obj->data = CallocInstance(size);
    MI_CpuCopy8(src, obj->data, size);
    obj->word0 = src->word0;
    obj->word1 = src->word1;
}
