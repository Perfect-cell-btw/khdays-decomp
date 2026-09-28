/* Resource callback: blits the entry's tile rectangle. */

extern void Ov008_BlitTileRect(void *, int);
void Ov008_ResourceNodeCallback(void *arg0)
{
    Ov008_BlitTileRect(arg0, 0);
}
