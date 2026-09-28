/* Copies the most recent valid touch sample (validity 0), or the last one, into out; returns out.
 */

extern int Touch_GetRecentSamples();
extern int MI_CpuCopy8();

struct Entry {
    int field0;
    short field4;
    unsigned short field6;
};

int Ov000_Touch_GetLatestValidSample(int a, int b) {
    struct Entry buf[4];
    int i;
    int last;

    last = Touch_GetRecentSamples(buf) - 1;
    for (i = last; i >= 0; i--) {
        if (buf[i].field6 == 0) {
            MI_CpuCopy8(&buf[i], b, 8);
            return b;
        }
    }
    MI_CpuCopy8(&buf[last], b, 8);
    return b;
}
