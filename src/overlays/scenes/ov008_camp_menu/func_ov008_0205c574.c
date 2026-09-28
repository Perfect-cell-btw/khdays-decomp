/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov008_TweenSlotValue. */
extern void *Ov008_TweenSlotValue();

void *func_ov008_0205c574(int arg0, int arg1, unsigned int arg2, unsigned int arg3) {
    return Ov008_TweenSlotValue(arg0, arg1, arg2, arg3);
}
