/* Resource callback: blits the entry's cell-buffer region. */

extern void Ov008_BlitCellBufferRegion(void *, int);
void Ov008_ResourceEntryCallback_2(void *arg0)
{
    Ov008_BlitCellBufferRegion(arg0, 1);
}
