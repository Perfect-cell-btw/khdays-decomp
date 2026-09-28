/* Forwards a region event to the shared enemy framework (Ov107_HandleRegionEvent). */

extern int Ov107_HandleRegionEvent(void *obj, void *region);

int func_ov201_020d2278(void *obj, void *region)
{
    return Ov107_HandleRegionEvent(obj, region);
}
