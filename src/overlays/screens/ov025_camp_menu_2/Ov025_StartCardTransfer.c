/* Begins the card transfer and marks it running. */

extern int Ov025_BeginCardTransfer();

void Ov025_StartCardTransfer(int arg0, int arg1) {
    Ov025_BeginCardTransfer(arg1);
    *(int *)(arg0 + 0x238) = 1;
}
