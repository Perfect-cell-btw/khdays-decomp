extern void Ov008_SweepReleasePendingElements(void *);
extern void Ov008_FlushFlaggedElements(void *, int);
extern void Ov008_SweepFreeElementBuffers(void *);
void Ov008_SweepElements(void *obj)
{
    Ov008_SweepReleasePendingElements(obj);
    Ov008_FlushFlaggedElements(obj, 0);
    Ov008_SweepFreeElementBuffers(obj);
}
