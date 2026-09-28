/* Ov105_WHi_MeasureChannel -- emit a scene event (id 0x11, prio 3, ttl 0x1e), ov105. Returns the WM
 * error code. */
extern int Ov105_WM_MeasureChannel(int target, int prio, int id, int arg, int ttl);
int Ov105_WHi_MeasureChannel(int target, int arg) {
    return Ov105_WM_MeasureChannel(target, 3, 0x11, arg, 0x1e);
}
