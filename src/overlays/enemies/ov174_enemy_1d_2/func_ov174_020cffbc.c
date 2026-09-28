/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov107_HandleRegionEvent. */
extern void *Ov107_HandleRegionEvent();

void *func_ov174_020cffbc() {
    return Ov107_HandleRegionEvent();
}
