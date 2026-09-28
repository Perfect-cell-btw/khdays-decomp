/* NitroSDK original assembly (libraries/os/src/os_context.c). */

#include "nitro/types.h"
#include "nitro/os.h"

asm void OS_InitContext (register OSContext * context, register u32 newpc, register u32 newsp)
{
    add newpc, newpc, #4
    str newpc, [context, #OS_CONTEXT_PC_PLUS4]
    str newsp, [context, #OS_CONTEXT_SP_SVC]
    sub newsp, newsp, #HW_SVC_STACK_SIZE
    tst newsp, #4
    subne newsp, newsp, #4
    str newsp, [context, #OS_CONTEXT_SP]
    ands r1, newpc, #1
    movne r1, #HW_PSR_SYS_MODE | HW_PSR_THUMB_STATE
    moveq r1, #HW_PSR_SYS_MODE | HW_PSR_ARM_STATE
    str r1, [context, #OS_CONTEXT_CPSR]
    mov r1, #0
    str r1, [context, #OS_CONTEXT_R0]
    str r1, [context, #OS_CONTEXT_R1]
    str r1, [context, #OS_CONTEXT_R2]
    str r1, [context, #OS_CONTEXT_R3]
    str r1, [context, #OS_CONTEXT_R4]
    str r1, [context, #OS_CONTEXT_R5]
    str r1, [context, #OS_CONTEXT_R6]
    str r1, [context, #OS_CONTEXT_R7]
    str r1, [context, #OS_CONTEXT_R8]
    str r1, [context, #OS_CONTEXT_R9]
    str r1, [context, #OS_CONTEXT_R10]
    str r1, [context, #OS_CONTEXT_R11]
    str r1, [context, #OS_CONTEXT_R12]
    str r1, [context, #OS_CONTEXT_LR]
    bx lr
}
