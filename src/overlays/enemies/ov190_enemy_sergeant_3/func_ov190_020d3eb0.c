/* Forwards a region event to the shared enemy framework (Ov107_HandleRegionEvent). */

extern int Ov107_HandleRegionEvent(void *obj, void *region);

int func_ov190_020d3eb0(void *obj, void *region)
{
    return Ov107_HandleRegionEvent(obj, region);
}
