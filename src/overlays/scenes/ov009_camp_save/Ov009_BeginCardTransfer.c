extern int func_02020904(void);
extern void Ov009_StartCardThread(int arg0, int arg1, int arg2);

extern unsigned char data_ov009_020563f8[];
extern void *data_0204be14;

void Ov009_BeginCardTransfer(int slot) {
    func_02020904();
    data_ov009_020563f8[0] = 0;
    data_ov009_020563f8[1] = (unsigned char)slot;
    Ov009_StartCardThread((data_ov009_020563f8[1] << 1) * 0x2018 + 0x20,
                        (int)data_0204be14, 0x2018);
}
