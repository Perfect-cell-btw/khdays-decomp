/* Creates a task in a task list (see game/ai_task.h): inserts the 0x28-byte entry, allocates its
 * zeroed state block of the given size, records its start and teardown callbacks and a new id;
 * returns the id and, when asked, the state block. */

#include "game/ai_task.h"

extern unsigned int List_InsertSorted(int list, int extra, unsigned int key);
extern void *CallocInstance(unsigned int size);
extern int data_02042ad8;

int CreateRegistryEntry(void *pList, unsigned int nPriority, unsigned int nStateSize,
                        void (*pfnStart)(), void (*pfnTeardown)(), void **ppState)
{
    AiTask *task = (AiTask *)List_InsertSorted((int)pList, sizeof(AiTask), nPriority);
    int id;
    task->pList = pList;
    task->pState = CallocInstance(nStateSize);
    task->pfnStart = pfnStart;
    task->pfnTeardown = pfnTeardown;
    task->stop = 0;
    id = data_02042ad8;
    data_02042ad8 = id + 1;
    task->id = id;
    if (ppState != 0)
        *ppState = task->pState;
    return task->id;
}
