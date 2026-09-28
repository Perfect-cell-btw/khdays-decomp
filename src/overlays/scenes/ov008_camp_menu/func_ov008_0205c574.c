/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov008_TweenSlotValue. */
extern void *Ov008_TweenSlotValue();

void *func_ov008_0205c574() {
    return Ov008_TweenSlotValue();
}
