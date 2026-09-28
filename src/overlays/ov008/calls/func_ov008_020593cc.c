/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov008_InitializeMenuEntryLayout. */
extern void *Ov008_InitializeMenuEntryLayout();

void *func_ov008_020593cc() {
    return Ov008_InitializeMenuEntryLayout();
}
