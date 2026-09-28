/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov008_Menu_AdvanceIntoPanel. */
extern void *Ov008_Menu_AdvanceIntoPanel();

void *func_ov008_0205968c(int arg0, int arg1, int arg2, int arg3) {
    return Ov008_Menu_AdvanceIntoPanel(arg0, arg1, arg2, arg3);
}
