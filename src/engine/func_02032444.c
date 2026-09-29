/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to SlotTable_AddEntry. */

#include "game/engine.h"

void *func_02032444(void *arg0, int arg1, int arg2) {
    return SlotTable_AddEntry(arg0, arg1, arg2);
}
