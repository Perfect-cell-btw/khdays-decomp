/* Starts the save-card read of a save slot: resets the card state, records the slot and starts the
 * card thread on that slot's block (0x2018 bytes each). */

extern int func_02020904(void);
extern void Ov025_StartCardThread(int arg0, int arg1, int arg2);

extern unsigned char data_ov025_020b5760[];
extern void *data_0204be14;

void Ov025_BeginCardTransfer(int slot) {
    func_02020904();
    data_ov025_020b5760[0] = 0;
    data_ov025_020b5760[1] = (unsigned char)slot;
    Ov025_StartCardThread((data_ov025_020b5760[1] << 1) * 0x2018 + 0x20,
                        (int)data_0204be14, 0x2018);
}
