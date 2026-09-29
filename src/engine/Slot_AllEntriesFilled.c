#include "game/engine.h"

extern unsigned char data_0204c678[];

int Slot_AllEntriesFilled(int a) {
    int ok = 1;
    int n = Slot_CalcRangeCap18(a);
    int i = 0;
    unsigned char *e;
    if (n > 0) {
        e = data_0204c678 + a * 260;
        do {
            if (*(unsigned short *)(e + 0xba) == 0) {
                ok = 0;
                break;
            }
            i = i + 1;
            e = e + 4;
        } while (i < n);
    }
    return ok;
}
