/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov107_HandleRegionEvent. */
extern void *Ov107_HandleRegionEvent(void *obj, void *region);

void *func_ov174_020cffbc(void *obj, void *region)
{
    return Ov107_HandleRegionEvent(obj, region);
}
