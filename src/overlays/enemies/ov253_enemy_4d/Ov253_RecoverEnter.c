/* Ov253_RecoverEnter -- recover entry: sends message data_ov253_020d48fc (kind 4) to the
 * actor's +0x24 hook when set, restores pose 1, clears the +0x1c timer and the +0x38 flag and
 * moves the node to 020cda5c. */
struct hpair { unsigned short a, b; };

extern void Ov107_PostTagUpdate(int actor, int pose, int flag);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern const struct hpair data_ov253_020d48fc;
extern void Ov253_TickSpin(void);

void Ov253_RecoverEnter(int *node) {
    int *state = (int *)node[1];
    struct hpair msg = data_ov253_020d48fc;
    void (*hook)(int, struct hpair *, int) = *(void (**)(int, struct hpair *, int))(*state + 0x24);

    if (hook != 0) {
        hook(*state, &msg, 4);
    }
    Ov107_PostTagUpdate(*state, 1, 0);
    state[7] = 0;
    *((unsigned char *)state + 0x38) = 0;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov253_TickSpin);
}
