/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov025_MergeSortList. */

#include "nnsys/fnd.h"

extern void *Ov025_MergeSortList(NNSFndList * list, int compare);

void *func_ov025_0208a5ec(NNSFndList * list, int compare)
{
    return Ov025_MergeSortList(list, compare);
}
