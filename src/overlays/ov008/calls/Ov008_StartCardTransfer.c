/* Begins the card transfer and marks it running. */

extern void Ov008_BeginCardTransfer(void *);
void Ov008_StartCardTransfer(char *obj, void *arg1)
{
    Ov008_BeginCardTransfer(arg1);
    *(int *)(obj + 0x238) = 1;
}
