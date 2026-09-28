/* Ov006_SetTickSlotByte -- store param_1 at ctx+0x42a, and (only when the tick source is up)
 * mirror it into the per-tick slot at ctx + tick + 0x48e. */
extern int data_ov006_020565e4;   /* -> Mission Mode-screen context */
extern int func_01ff8128(void);

void Ov006_SetTickSlotByte(unsigned char param_1) {
    *(unsigned char *)(data_ov006_020565e4 + 0x42a) = param_1;
    if (func_01ff8128() != 0) {
        return;
    }
    *(unsigned char *)(data_ov006_020565e4 + func_01ff8128() + 0x48e) = param_1;
}
