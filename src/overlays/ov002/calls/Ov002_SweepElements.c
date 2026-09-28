extern int Ov002_SweepReleasePendingElements();
extern int Ov002_FlushFlaggedElements();
extern int Ov002_SweepFreeElementBuffers();

void Ov002_SweepElements(int arg0) {
    Ov002_SweepReleasePendingElements(arg0);
    Ov002_FlushFlaggedElements(arg0, 0);
    Ov002_SweepFreeElementBuffers(arg0);
}
