/* AI step: once the actor is active (bit 0 of its flags at +0x60), makes its stored action (+0x1c9)
 * the pending action (+0x1c7) and clears the step handler. */

extern int SetIndexedSlot();

struct Sub {
    char _pad[0x60];
    unsigned short flags;       /* 0x60 */
    char _pad2[0x1c7 - 0x62];
    signed char field_1c7;      /* 0x1c7 */
    signed char _pad3;          /* 0x1c8 */
    signed char field_1c9;      /* 0x1c9 */
};

struct Obj {
    char _pad0[4];
    struct Sub **pp;            /* 0x04 */
    char _pad1[0x20 - 8];
    signed char field_20;      /* 0x20 */
};

void Ov284_AiStep_QueueStoredActionIfActive(struct Obj *this) {
    struct Sub *s = *this->pp;
    if ((unsigned)(s->flags << 24) >> 24 & 1) {
        s->field_1c7 = s->field_1c9;
        SetIndexedSlot(this, this->field_20, 0);
    }
}
