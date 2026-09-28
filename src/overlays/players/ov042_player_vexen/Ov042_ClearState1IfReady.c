/* While the effect slot is in state 1, advances its tracks and returns it to idle when they finish.
 */

extern unsigned short Sequence_UpdateTracks();

void Ov042_ClearState1IfReady(int this_, int delta) {
    int s = *(int *)this_;
    if (s == 0) return;
    if (s != 1) return;
    if (Sequence_UpdateTracks(this_ + 4, delta) != 0) {
        *(int *)this_ = 0;
    }
}
