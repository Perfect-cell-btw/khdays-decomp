/* While the effect slot is active, advances its tracks and marks it idle when they finish. */

extern int Sequence_UpdateTracks();

void Ov033_ClearStateIfReadyWhenActive(int this_) {
    if (*(int *)this_ != 1) return;
    if (Sequence_UpdateTracks(this_ + 8) != 0) {
        *(int *)this_ = 0;
    }
}
