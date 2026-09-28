/* Releases pending elements, flushes the flagged ones and frees their buffers; returns the
 * element count Ov008_SweepFreeElementBuffers leaves. */

extern void Ov008_SweepReleasePendingElements(void *);
extern void Ov008_FlushFlaggedElements(void *, int);
extern int Ov008_SweepFreeElementBuffers(void *);
int Ov008_SweepElements(void *obj)
{
    Ov008_SweepReleasePendingElements(obj);
    Ov008_FlushFlaggedElements(obj, 0);
    return Ov008_SweepFreeElementBuffers(obj);
}
