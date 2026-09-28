/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov107_HandleRegionEvent. */
extern void *Ov107_HandleRegionEvent(void *obj, void *region);

void *func_ov173_020cc37c(void *obj, void *region)
{
    return Ov107_HandleRegionEvent(obj, region);
}
