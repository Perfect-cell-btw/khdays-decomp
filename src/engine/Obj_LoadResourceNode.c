typedef unsigned int u32;

struct Node {
    char _00[0x5c];
    struct Node *next;
};

extern struct Node *NNSi_FndAllocFromDefaultExpHeap(int size);
extern void NNS_G2dInitImageProxy(void *);
extern void NNS_G2dInitImagePaletteProxy(void *);
extern void MI_CpuFill8(void *dst, int val, u32 n);
extern void SpriteRes_Load(void *a, void *b, struct Node *node);

int Obj_LoadResourceNode(void *a, void *b)
{
    struct Node *node;
    struct Node *cur;
    int count;

    count = 0;
    node = NNSi_FndAllocFromDefaultExpHeap(0x64);
    NNS_G2dInitImageProxy((char *)node + 0x34);
    NNS_G2dInitImagePaletteProxy((char *)node + 0x20);
    MI_CpuFill8(node, 0, 0x20);
    SpriteRes_Load(a, b, node);
    cur = *(struct Node **)((char *)a + 0x4620);
    if (cur == 0) {
        *(struct Node **)((char *)a + 0x4620) = node;
    } else {
        struct Node *nx;
        nx = cur->next;
        count++;
        while (nx != 0) {
            cur = nx;
            nx = cur->next;
            count++;
        }
        cur->next = node;
    }
    node->next = 0;
    return count;
}
