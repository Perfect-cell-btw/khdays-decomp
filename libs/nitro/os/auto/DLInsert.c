#include "nitro/types.h"
#include "nitro/os.h"

typedef void *OSMessage;

#define NULL ((void *)0)
#define HW_MAIN_MEM 0x02000000

/* NitroSDK os_alloc.c: the arena heap allocator (free-list cells of 32-byte-aligned blocks). */
typedef int OSArenaId;
typedef int OSHeapHandle;
#define OS_ARENA_MAX 9

#define OFFSET(n, a)    (((u32) (n)) & ((a) - 1))
#define TRUNC(n, a)     (((u32) (n)) & ~((a) - 1))
#define ROUND(n, a)     (((u32) (n) + (a) - 1) & ~((a) - 1))

#define ALIGNMENT       32
#define MINOBJSIZE      (HEADERSIZE + ALIGNMENT)
#define HEADERSIZE      ROUND(sizeof(Cell), ALIGNMENT)

typedef struct Cell Cell;
typedef struct HeapDesc HeapDesc;

struct Cell {
    Cell *prev;                   /* 0x00 */
    Cell *next;                   /* 0x04 */
    long size;                    /* 0x08 */
};

struct HeapDesc {
    long size;                    /* 0x00 */
    Cell *free;                   /* 0x04 */
    Cell *allocated;              /* 0x08 */
};

typedef struct {
    volatile OSHeapHandle currentHeap;   /* 0x00 */
    int numHeaps;                 /* 0x04 */
    void *arenaStart;             /* 0x08 */
    void *arenaEnd;               /* 0x0c */
    HeapDesc *heapArray;          /* 0x10 */
} OSHeapInfo;

extern void *data_02044590[OS_ARENA_MAX];   /* OSiHeapInfo */
#define OSiHeapInfo data_02044590
extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern Cell *DLAddFront(Cell *list, Cell *cell);
extern Cell *DLExtract(Cell *list, Cell *cell);

/* DLInsert -- NitroSDK os_alloc.c. */
Cell * DLInsert (Cell * list, Cell * cell)
{
    Cell * prev;
    Cell * next;

    for (next = list, prev = NULL; next; prev = next, next = next->next) {
        if (cell <= next) {
            break;
        }
    }

    cell->next = next;
    cell->prev = prev;

    if (next) {
        next->prev = cell;
        if ((char *)cell + cell->size == (char *)next) {

            cell->size += next->size;
            cell->next = next = next->next;
            if (next) {
                next->prev = cell;
            }
        }
    }

    if (prev) {
        prev->next = cell;
        if ((char *)prev + prev->size == (char *)cell) {
            prev->size += cell->size;
            prev->next = next;
            if (next) {
                next->prev = prev;
            }
        }
        return list;
    } else {
        return cell;
    }
}
