extern int PMi_SetLED(int param_1);
extern int PMi_SetLEDAsync(int, void *, void *);
extern int PMi_SetAmp(int value);

extern struct { char _0[0x10]; int field_10; int field_14; } data_020463cc;

int PMi_SetLCDPower(int mode, int chan, int useTimeout, int useRoute)
{
    volatile unsigned short *reg_powcnt1 = (volatile unsigned short *)0x04000304;

    if (mode != 0) {
        if (mode == 1) {
            if (useTimeout == 0) {
                if ((unsigned int)(*(int *)0x027ffc3c - data_020463cc.field_10) <= 7) {
                    return 0;
                }
            }

            if (chan != 0) {
                if (useRoute != 0) {
                    PMi_SetLED(chan);
                } else {
                    PMi_SetLEDAsync(chan, 0, 0);
                }
            }
            *reg_powcnt1 |= 1;
            PMi_SetAmp(data_020463cc.field_14);
        }
    } else {
        PMi_SetAmp(0);
        *reg_powcnt1 &= ~1;
        data_020463cc.field_10 = *(int *)0x027ffc3c;
        if (chan != 0) {
            if (useRoute != 0) {
                PMi_SetLED(chan);
            } else {
                PMi_SetLEDAsync(chan, 0, 0);
            }
        }
    }
    return 1;
}
