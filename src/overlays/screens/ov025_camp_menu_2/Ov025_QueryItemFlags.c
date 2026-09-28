/* Ov025_QueryItemFlags -- query (and optionally set) item param_1's two flags.
 * When param_2 is set, marks it in the "owned" set (ctx+0x238) first. Returns bit0 = owned,
 * bit1 = present in the second set (ctx+0x248). */
extern int  Ov025_GetPageA(void);
extern void BitArray_SetBit(int set, unsigned int bit);
extern int  BitArray_TestBit(int set, unsigned int bit);

unsigned int Ov025_QueryItemFlags(unsigned int param_1, unsigned int param_2) {
    int ctx = Ov025_GetPageA();
    if (param_2 != 0) {
        BitArray_SetBit(ctx + 0x238, param_1);
    }
    param_2 = (BitArray_TestBit(ctx + 0x238, param_1) != 0);
    return param_2 | (unsigned int)(BitArray_TestBit(ctx + 0x248, param_1) != 0) << 1;
}
