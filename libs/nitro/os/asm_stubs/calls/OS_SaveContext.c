/* NitroSDK original assembly (libraries/os/src/os_context.c). */

#include "nitro/types.h"
#include "nitro/os.h"

extern void CP_SaveContext(void);

asm BOOL OS_SaveContext (register OSContext * context)
{
    stmfd sp !, { lr, r0 }
    add r0, r0, #OS_CONTEXT_CP_CONTEXT
    ldr r1, = CP_SaveContext
    blx r1
    ldmfd sp !, { lr, r0 }
    add r1, r0, #OS_CONTEXT_CPSR
    mrs r2, cpsr
    str r2, [r1], #OS_CONTEXT_R0 - OS_CONTEXT_CPSR
    mov r0, #HW_PSR_SVC_MODE | HW_PSR_IRQ_DISABLE | HW_PSR_FIQ_DISABLE | HW_PSR_ARM_STATE
    msr cpsr_c, r0
    str sp, [r1, #OS_CONTEXT_SP_SVC - OS_CONTEXT_R0]
    msr cpsr_c, r2
    mov r0, #1
    stmia r1, {r0 - r14}
    add r0, pc, #8
    str r0, [r1, #OS_CONTEXT_PC_PLUS4 - OS_CONTEXT_R0]
    mov r0, #0
    bx lr
}
