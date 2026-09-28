/* Clears the 0x14-byte pending scene record; returns 1. */

extern int MI_CpuFill8();
extern char data_0204bda8[];

int Scene_ClearPending(void) {
    MI_CpuFill8(data_0204bda8, 0, 0x14);
    return 1;
}
