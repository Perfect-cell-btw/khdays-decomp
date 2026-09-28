#include "nitro/types.h"
#include "nitro/os.h"
typedef void *OSMessage;

#define NULL ((void *)0)
#define HW_MAIN_MEM 0x02000000

typedef struct {
    void * prevObject;
    void * nextObject;
} NNSFndLink;
typedef struct {
    void * headObject;
    void * tailObject;
    u16 numObjects;
    u16 offset;
} NNSFndList;
void * NNS_FndGetNextListObject(NNSFndList * list, void * object);
extern void * NNS_FndGetNextListObject (NNSFndList * list, void * object);

/* NNS_FndGetNthListObject -- NitroSystem list.c: NNS_FndGetNthListObject. */
void * NNS_FndGetNthListObject (NNSFndList * list, u16 index)
{
    int count = 0;
    NNSFndLink * object = NULL;

    while ((object = NNS_FndGetNextListObject(list, object)) != NULL)
    {
        if (index == count) {
            return object;
        }
        count++;
    }
    return NULL;
}
