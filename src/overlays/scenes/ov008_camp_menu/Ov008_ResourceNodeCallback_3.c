/* Resource callback: blits the entry's queued image. */

extern void Ov008_BlitQueuedImage(void *, int);
void Ov008_ResourceNodeCallback_3(void *arg0)
{
    Ov008_BlitQueuedImage(arg0, 0);
}
