/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov008_Menu_AdvanceIntoPanel. */
extern void *Ov008_Menu_AdvanceIntoPanel();

void *func_ov008_0205968c() {
    return Ov008_Menu_AdvanceIntoPanel();
}
