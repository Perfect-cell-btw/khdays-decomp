extern void Ov146_Rider_SetFlagIfReady(int a, int b);
extern void SetIndexedSlot(int self, int index, void *cb);
struct hw60 { unsigned short lo:8, hi:8; };
void Ov146_BeginQueuedPose(int self) {
    int obj = *(int *)(self + 4);
    if ((((struct hw60 *)(*(int *)obj + 0x60))->lo & 1) == 0) {
        return;
    }
    *(int *)(obj + 0x58) = 1;
    Ov146_Rider_SetFlagIfReady(*(int *)(obj + 8), 1);
    *(signed char *)(*(int *)obj + 0x1c7) = *(signed char *)(*(int *)obj + 0x1c9);
    SetIndexedSlot(self, *(signed char *)(self + 0x20), 0);
}
