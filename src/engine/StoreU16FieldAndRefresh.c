/* Requests a BGM load by id: marks the request pending, records the id, clears the BGM sound heap
 * and posts the id request to the loader. */

extern void NNS_SndHeapClear(void *node);
extern void Loader_PostIdRequest(unsigned int a, void *node, void *dst);
extern char *data_0204c234;

void StoreU16FieldAndRefresh(unsigned int param_1)
{
    char *base = data_0204c234;

    *(unsigned char *)(base + 0xb46fc) = 1;
    *(unsigned short *)(base + 0xb46f6) = param_1;
    NNS_SndHeapClear(*(void **)(base + 0xb04b4));
    Loader_PostIdRequest((unsigned short)param_1, *(void **)(base + 0xb04b4), base + 0xb46fc);
}
