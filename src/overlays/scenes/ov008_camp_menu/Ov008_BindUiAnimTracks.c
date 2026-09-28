/* Binds the UI animation tracks listed in the overlay's table to the object's animation set. */

#include "nitro/types.h"

extern void BindAnimTrack(int obj, unsigned int trackId, int animBlock, int param_2);
extern const u16 data_ov008_0208f044[];

void Ov008_BindUiAnimTracks(int param_1, int param_2) {
    u16 tracks[6];
    u16 *p = tracks;
    unsigned int i;
    p[0] = data_ov008_0208f044[0];
    p[1] = data_ov008_0208f044[1];
    p[2] = data_ov008_0208f044[2];
    p[3] = data_ov008_0208f044[3];
    p[4] = data_ov008_0208f044[4];
    i = 0;
    do {
        BindAnimTrack(param_1, p[i], param_1 + 0xe0, param_2);
        i++;
    } while (i < 5);
}
