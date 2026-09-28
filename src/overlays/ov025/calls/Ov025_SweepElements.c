/* Releases pending elements, flushes the flagged ones and frees their buffers. */

extern int Ov025_SweepReleasePendingElements();
extern int Ov025_FlushFlaggedElements();
extern int Ov025_SweepFreeElementBuffers();

void Ov025_SweepElements(int arg0) {
    Ov025_SweepReleasePendingElements(arg0);
    Ov025_FlushFlaggedElements(arg0, 0);
    Ov025_SweepFreeElementBuffers(arg0);
}
