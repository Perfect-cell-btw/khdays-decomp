/* Sets the main screen brightness from an fx32 value (and the sub screen's in mode 0x2a). */

extern void SetMasterBrightnessMain(int arg0);
extern short LoadGlobalU16At0(void);
extern void SetMasterBrightnessSub(int arg0);

void func_ov022_02086d60(int arg0) {
    SetMasterBrightnessMain(arg0 >> 0xc);
    if (LoadGlobalU16At0() == 0x2a) {
        SetMasterBrightnessSub(arg0 >> 0xc);
    }
}
