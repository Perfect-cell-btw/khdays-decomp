/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov005_ClearStateFreeLists. */
extern void *Ov005_ClearStateFreeLists();

void *Ov005_ReleasePanelViewVeneer(char *r4) {
    return Ov005_ClearStateFreeLists(r4);
}
