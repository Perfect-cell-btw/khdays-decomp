/* Ov245_WaitPartsSettled -- wait until every part is settled: walks the actor's nine +0x3fc parts;
 * a part with a +0x38c handle whose +0x60 low byte has bit 0 set, bit 7 clear and bit 0 of +0x17a
 * set keeps waiting (return). Once all pass, the actor is reset (020cce28) and the node moves to
 * 020cdc78. */
extern void Ov245_ResetMode(int actor);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov245_AiStep_QueueAction2AfterGate(void);

struct Ov245Parts { char pad[0x3fc]; int parts[9]; };
struct hw60 { unsigned short lo : 8, hi : 8; };
struct Bit0 { unsigned char bit0 : 1; };

void Ov245_WaitPartsSettled(int *node) {
    int actor = *(int *)node[1];
    int i;

    for (i = 0; i < 9; i++) {
        int part = ((struct Ov245Parts *)actor)->parts[i];
        if (*(int *)(part + 0x38c) != 0) {
            if ((((struct hw60 *)(part + 0x60))->lo & 1) == 0) {
                return;
            }
            if ((((struct hw60 *)(part + 0x60))->lo & 0x80) != 0) {
                return;
            }
            if (!((struct Bit0 *)(part + 0x17a))->bit0) {
                return;
            }
        }
    }
    Ov245_ResetMode(actor);
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov245_AiStep_QueueAction2AfterGate);
}
