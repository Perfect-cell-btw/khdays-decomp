/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov022_EnterBlockReaction. */
extern void *Ov022_EnterBlockReaction(void *pCtx);

void *Ov022_VeneerTo_Ov022_EnterBlockReaction(void *pCtx)
{
    return Ov022_EnterBlockReaction(pCtx);
}
