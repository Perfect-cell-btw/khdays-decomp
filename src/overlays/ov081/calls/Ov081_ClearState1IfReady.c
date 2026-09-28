extern int Sequence_UpdateTracks();

void Ov081_ClearState1IfReady(int this_) {
    int s = *(int *)this_;
    if (s == 0) return;
    if (s != 1) return;
    if (Sequence_UpdateTracks(this_ + 4) != 0) {
        *(int *)this_ = 0;
    }
}
