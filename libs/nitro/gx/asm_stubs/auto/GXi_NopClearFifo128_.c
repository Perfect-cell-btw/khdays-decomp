#include "nitro/types.h"
#include "nitro/os.h"
typedef void *OSMessage;

#define NULL ((void *)0)
#define HW_MAIN_MEM 0x02000000

#define offsetof(type, member) ((u32)&(((type *)0)->member))

/* GXi_NopClearFifo128_ -- NitroSDK g3x.c: GXi_NopClearFifo128_. */
asm void GXi_NopClearFifo128_ (register void *pDest)
{
	mov r1, #0
	mov r2, #0
	mov r3, #0
	mov r12, #0
	stmia r0, {r1 - r3, r12}
	stmia r0, {r1 - r3, r12}
	stmia r0, {r1 - r3, r12}
	stmia r0, {r1 - r3, r12}
	stmia r0, {r1 - r3, r12}
	stmia r0, {r1 - r3, r12}
	stmia r0, {r1 - r3, r12}
	stmia r0, {r1 - r3, r12}
	stmia r0, {r1 - r3, r12}
	stmia r0, {r1 - r3, r12}
	stmia r0, {r1 - r3, r12}
	stmia r0, {r1 - r3, r12}
	stmia r0, {r1 - r3, r12}
	stmia r0, {r1 - r3, r12}
	stmia r0, {r1 - r3, r12}
	stmia r0, {r1 - r3, r12}
	stmia r0, {r1 - r3, r12}
	stmia r0, {r1 - r3, r12}
	stmia r0, {r1 - r3, r12}
	stmia r0, {r1 - r3, r12}
	stmia r0, {r1 - r3, r12}
	stmia r0, {r1 - r3, r12}
	stmia r0, {r1 - r3, r12}
	stmia r0, {r1 - r3, r12}
	stmia r0, {r1 - r3, r12}
	stmia r0, {r1 - r3, r12}
	stmia r0, {r1 - r3, r12}
	stmia r0, {r1 - r3, r12}
	stmia r0, {r1 - r3, r12}
	stmia r0, {r1 - r3, r12}
	stmia r0, {r1 - r3, r12}
	stmia r0, {r1 - r3, r12}
	bx lr
}
