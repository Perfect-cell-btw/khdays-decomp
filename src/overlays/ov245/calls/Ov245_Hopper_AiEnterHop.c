/* Clear bit 0x80 in the high byte of the u16 flags at *(obj)+0x60 and register the handler. */
struct hw60 { unsigned short lo : 8; unsigned short hi : 8; };
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov245_HopTick(int);
void Ov245_Hopper_AiEnterHop(int param_1) {
    int obj = *(int *)*(int *)(param_1 + 4);
    ((struct hw60 *)(obj + 0x60))->hi &= ~0x80;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov245_HopTick);
}
