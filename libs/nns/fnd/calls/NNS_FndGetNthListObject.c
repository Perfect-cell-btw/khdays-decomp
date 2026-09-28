

#include "nitro/types.h"
#include "nitro/os.h"
#include "nnsys/fnd.h"

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
