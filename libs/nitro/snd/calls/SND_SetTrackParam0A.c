/* NitroSDK SND: sets the 16-bit track parameter at offset 0xa for the tracks. */

extern void SNDi_SetTrackParam(int a, int b, int c, int d, int e);

void SND_SetTrackParam0A(int a, int b, int c) {
    SNDi_SetTrackParam(a, b, 0xa, c, 2);
}
