/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov008_GetMenuContext. */
extern void *Ov008_GetMenuContext();

void *func_ov008_020698ec() {
    return Ov008_GetMenuContext();
}
