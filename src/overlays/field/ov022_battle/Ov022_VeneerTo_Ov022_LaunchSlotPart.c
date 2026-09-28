/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov022_LaunchSlotPart. */
extern void *Ov022_LaunchSlotPart(void *pCtx);

void *Ov022_VeneerTo_Ov022_LaunchSlotPart(void *pCtx)
{
    return Ov022_LaunchSlotPart(pCtx);
}
