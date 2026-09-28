extern void Ov008_BlitQueuedImage(void *, int);
void Ov008_ResourceEntryCallback_3(void *arg0)
{
    Ov008_BlitQueuedImage(arg0, 1);
}
