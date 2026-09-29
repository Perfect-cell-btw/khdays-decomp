/* Returns the frame-rate mode (data_0204c058 byte 0). main starts every frame on a V-blank and then
 * waits for one more (mode 0), two more (mode 1) or none (mode 2): 0 = 30 fps, 1 = 20 fps,
 * 2 = 60 fps. Game code scales per-frame speeds and timings by 1.5 in mode 1. */

extern int data_0204c058;

int GetFrameRateMode(void) {
    return *(unsigned char *)&data_0204c058;
}
