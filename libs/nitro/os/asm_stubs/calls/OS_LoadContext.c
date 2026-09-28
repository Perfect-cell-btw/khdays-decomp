/* NitroSDK original assembly (libraries/os/src/os_context.c). */

#include "nitro/types.h"
#include "nitro/os.h"

extern void CPi_RestoreContext(void);

asm void OS_LoadContext (register OSContext * context)
{
    stmfd sp !, { lr, r0 }
    add r0, r0, #OS_CONTEXT_CP_CONTEXT
    ldr r1, = CPi_RestoreContext
    blx r1
    ldmfd sp !, { lr, r0 }
    mrs r1, cpsr
    bic r1, r1, #HW_PSR_CPU_MODE_MASK
    orr r1, r1, #HW_PSR_SVC_MODE | HW_PSR_IRQ_DISABLE | HW_PSR_FIQ_DISABLE
    msr cpsr_c, r1
    ldr r1, [r0], #OS_CONTEXT_R0 - OS_CONTEXT_CPSR
    msr spsr_fsxc, r1
    ldr sp, [r0, #OS_CONTEXT_SP_SVC - OS_CONTEXT_R0]
    ldr lr, [r0, #OS_CONTEXT_PC_PLUS4 - OS_CONTEXT_R0]
    ldmia r0, { r0 - r14 }^
    nop
    subs pc, lr, #4
}
