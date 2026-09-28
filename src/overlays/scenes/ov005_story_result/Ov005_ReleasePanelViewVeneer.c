/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov005_ClearStateFreeLists. */
extern void *Ov005_ClearStateFreeLists();

void *Ov005_ReleasePanelViewVeneer() {
    return Ov005_ClearStateFreeLists();
}
