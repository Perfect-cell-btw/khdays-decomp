/* Returns the gauge rate for a count out of a total, scaled by the frame-rate mode. */

extern int FX_Div(int arg0, int arg1);
extern int gObjSystem;

int func_ov022_02094678(int arg0, unsigned int arg1) {
    unsigned char c = *(unsigned char *)&gObjSystem;
    int r;
    int x;
    switch (c) {
    case 0:
        r = 0x96;
        break;
    case 1:
        r = 100;
        break;
    case 2:
        r = 0x96;
        break;
    default:
        r = 0x96;
        break;
    }
    if (arg1 <= 1) {
        x = 0x1000;
    } else {
        x = 0x1000 - FX_Div(arg0 << 0xc, arg1 << 0xc);
    }
    return r * x;
}
