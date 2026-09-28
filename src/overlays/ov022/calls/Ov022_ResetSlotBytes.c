/* Reset the slot bytes. The -1 fields are SIGNED char: a signed -1 store lets mwcc
 * derive the value from the zero register (sub rX,rZero,#1), while an unsigned 0xff
 * store materialises `mov #0xff` and loses the match. */
extern int Ov022_IsByte8ZeroOr3(int);
void Ov022_ResetSlotBytes(int arg0) {
    if (!Ov022_IsByte8ZeroOr3(arg0)) return;
    *(signed char *)(arg0 + 8) = 0;
    *(signed char *)(arg0 + 10) = -1;
    *(signed char *)(arg0 + 0xb) = -1;
    *(signed char *)(arg0 + 0xe) = 0;
    *(signed char *)(arg0 + 9) = 0;
}
