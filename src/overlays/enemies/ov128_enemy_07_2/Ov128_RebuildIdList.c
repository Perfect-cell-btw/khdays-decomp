/* Rebuilds the actor's id list at +0x398 from a caller-supplied word array:
   frees the existing nodes, re-initialises the list, then appends one node per
   word. The count arrives in bytes and is turned into words in place. */

#include "game/engine.h"

extern void NNSi_FndDestroyDoubleList(void *list);
extern void List_Init(void *list);

void Ov128_RebuildIdList(char *self, int nCount, const int *pSrc)
{
    int i;

    NNSi_FndDestroyDoubleList(self + 0x398);
    List_Init(self + 0x398);
    nCount = (unsigned int)nCount >> 2;
    i = 0;
    if (nCount <= 0) {
        return;
    }
    do {
        int *pNode = List_InsertSorted(self + 0x398, 4, 100);
        *pNode = *pSrc++;
        i++;
    } while (i < nCount);
}
