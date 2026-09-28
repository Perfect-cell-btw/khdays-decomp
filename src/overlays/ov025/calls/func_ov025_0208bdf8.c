/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov025_MenuBack. */
extern void *Ov025_MenuBack();

void *func_ov025_0208bdf8() {
    return Ov025_MenuBack();
}
