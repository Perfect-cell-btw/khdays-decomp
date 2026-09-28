/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov008_HandleCancelFlags. */
extern void *Ov008_HandleCancelFlags();

void *func_ov008_020594c4() {
    return Ov008_HandleCancelFlags();
}
