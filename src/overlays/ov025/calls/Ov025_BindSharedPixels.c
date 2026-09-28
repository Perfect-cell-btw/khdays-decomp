/* Points both pixel buffers of the object at the shared pixel area. */

extern int Ov025_GetCtxBlock968c();

void Ov025_BindSharedPixels(int arg0) {
    int x = Ov025_GetCtxBlock968c();
    *(int *)arg0 = x;
    *(int *)(arg0 + 0x20) = x;
}
