/* Only when bit 0 of *(obj)+0x17a is set, play the anim (ov107 mode 4) and register the handler. */
struct bit0 { unsigned char b : 1; };
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov283_TickBounce(int);
void Ov283_AiLandBounce(int param_1) {
    int obj = *(int *)*(int *)(param_1 + 4);
    if (((struct bit0 *)(obj + 0x17a))->b == 0) return;
    Ov107_PostTagUpdate(obj, 4, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov283_TickBounce);
}
