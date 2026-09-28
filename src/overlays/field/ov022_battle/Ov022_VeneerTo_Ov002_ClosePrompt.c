/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov002_ClosePrompt. */
extern void *Ov002_ClosePrompt(int bClick);

void *Ov022_VeneerTo_Ov002_ClosePrompt(int bClick)
{
    return Ov002_ClosePrompt(bClick);
}
