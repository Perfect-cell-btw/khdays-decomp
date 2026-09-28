/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov025_BlitClampedSlot. */
extern void *Ov025_BlitClampedSlot();

void *func_ov025_0208eb08() {
    return Ov025_BlitClampedSlot();
}
