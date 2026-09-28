/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov025_BlitClampedSlot. */
extern void *Ov025_BlitClampedSlot();

void *func_ov025_0208eb08(int arg0, int arg1, unsigned int arg2, unsigned int arg3) {
    return Ov025_BlitClampedSlot(arg0, arg1, arg2, arg3);
}
