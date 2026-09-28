/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov008_MergeSortList. */

#include "nnsys/fnd.h"

extern void *Ov008_MergeSortList(NNSFndList * list, int compare);

void *func_ov008_0205697c(NNSFndList * list, int compare)
{
    return Ov008_MergeSortList(list, compare);
}
