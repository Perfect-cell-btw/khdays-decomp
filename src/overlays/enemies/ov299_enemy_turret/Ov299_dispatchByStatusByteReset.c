/* AI dispatcher: when an action is pending, makes it current and installs its step handler (rest or
 * attack). */

extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov299_AiEnterRest(void);
extern void Ov299_AttackEntry(void);
void Ov299_dispatchByStatusByteReset(int *node) {
    int *state = (int *)node[1];
    signed char c = *(signed char *)(*state + 0x1c7);
    if (c != -1) {
        *(signed char *)(*state + 0x1c6) = c;
        switch (*(signed char *)(*state + 0x1c6)) {
        case 0:
            SetIndexedSlot(node, 1, Ov299_AiEnterRest);
            break;
        case 1:
            SetIndexedSlot(node, 1, Ov299_AttackEntry);
            break;
        }
    }
    *(signed char *)(*state + 0x1c7) = 0xff;
}
