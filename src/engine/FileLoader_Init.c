/* FileLoader_Init -- start the file loader, MAIN. Once only (the 0x1800-byte work area is the marker):
 * allocates and clears the work area, the 0x420-byte streaming reader and the 0x460-byte reader
 * with its FSFile at +0x400, chains a pool of 32 requests (0x30 bytes each) into the free list,
 * clears the wait queue at +0x44c of the second reader, installs the two request hooks (EnqueueGfxCmd0 / EnqueueGfxCmd1), sets up the 32-slot request
 * queue and starts the loader thread (FileLoader_ThreadMain, priority 0x11, 0x240-byte stack in DTCM).
 * Returns TRUE. */

#include "nitro/types.h"

typedef struct OSThreadQueue {
    struct OSThread *head;
    struct OSThread *tail;
} OSThreadQueue;

static inline void OS_InitThreadQueue(OSThreadQueue *queue)
{
    queue->head = queue->tail = 0;
}

typedef struct LoaderRequest {
    struct LoaderRequest *next;         /* +0x00 */
    char pad04[0x30 - 4];
} LoaderRequest;

typedef struct FileLoader {
    char *reader;                       /* +0x00: streaming reader (0x420) */
    char *reader2;                      /* +0x04: reader with FSFile at +0x400 (0x460) */
    void *work;                         /* +0x08: 0x1800-byte work area */
    void *hookA;                        /* +0x0c */
    void *hookB;                        /* +0x10 */
    int **heap;                         /* +0x14 */
    LoaderRequest *freeList;            /* +0x18 */
    LoaderRequest *pool;                /* +0x1c */
} FileLoader;

extern FileLoader data_0204bbfc;
extern int **data_0204c024;             /* default heap */
extern void *data_0204bc1c;             /* request queue */
extern void *data_0204bc3c[32];         /* request queue buffer */
extern char data_0204bcbc[];            /* loader thread */
extern char data_027e0350[];            /* loader thread stack top (DTCM) */
extern void *AllocFromExpHeapWrapper(u32 size, int **heap);
extern void *ExpHeap_AllocOrDefault(u32 size, int align, int **heap);
extern void MI_CpuFill8(void *dest, int data, u32 size);
extern void FS_InitFile(void *file);
extern void EnqueueGfxCmd0(void);
extern void EnqueueGfxCmd1(void);
extern void FileLoader_ThreadMain(void *arg);
extern void OS_InitMessageQueue(void *mq, void **msgArray, int msgCount);
extern void OS_CreateThread(void *thread, void (*func)(void *), void *arg, void *stack, u32 stackSize, u32 prio);
extern void OS_WakeupThreadDirect(void *thread);

BOOL FileLoader_Init(void)
{
    int i;

    if (data_0204bbfc.work == 0) {
        data_0204bbfc.work = AllocFromExpHeapWrapper(0x1800, data_0204c024);
        MI_CpuFill8(data_0204bbfc.work, 0, 0x1800);
        data_0204bbfc.reader = ExpHeap_AllocOrDefault(0x420, 0x20, data_0204c024);
        data_0204bbfc.reader2 = ExpHeap_AllocOrDefault(0x460, 0x20, data_0204c024);
        FS_InitFile(data_0204bbfc.reader2 + 0x400);
        data_0204bbfc.pool = AllocFromExpHeapWrapper(0x600, data_0204c024);
        for (i = 0; i < 32; i++) {
            data_0204bbfc.pool[i].next = (i < 31) ? &data_0204bbfc.pool[i + 1] : 0;
        }
        data_0204bbfc.freeList = data_0204bbfc.pool;
        data_0204bbfc.hookA = EnqueueGfxCmd0;
        data_0204bbfc.hookB = EnqueueGfxCmd1;
        OS_InitMessageQueue(&data_0204bc1c, data_0204bc3c, 32);
        OS_InitThreadQueue((OSThreadQueue *)(data_0204bbfc.reader2 + 0x44c));
        OS_CreateThread(data_0204bcbc, FileLoader_ThreadMain, 0, data_027e0350, 0x240, 0x11);
        OS_WakeupThreadDirect(data_0204bcbc);
    }
    return 1;
}
