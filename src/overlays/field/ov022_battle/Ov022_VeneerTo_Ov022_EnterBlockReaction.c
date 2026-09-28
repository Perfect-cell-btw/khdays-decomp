/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov022_EnterBlockReaction. */
extern void *Ov022_EnterBlockReaction();

void *Ov022_VeneerTo_Ov022_EnterBlockReaction() {
    return Ov022_EnterBlockReaction();
}
