/* Ov025_IsTransferIdle -- is the ov025 transfer idle? True when bit 2 of the flags word at +0x28 is
 * clear AND the pending handle at +0x1f4 is null. */
extern int Ov025_GetPageB(void);

struct Ov025Flags { unsigned int lo : 2, bit2 : 1, rest : 29; };

int Ov025_IsTransferIdle(void) {
    int ctx = Ov025_GetPageB();
    return ((struct Ov025Flags *)(ctx + 0x28))->bit2 == 0 && *(int *)(ctx + 0x1f4) == 0;
}
