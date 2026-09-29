/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Obj_Destroy. */

#include "game/engine.h"

void *func_02023ad0(int *arg0) {
    return Obj_Destroy(arg0);
}
