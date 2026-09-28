/* AI step: once the actor is active (bit 0 of its flags at +0x60), sets its pending action (+0x1c7)
 * and clears the step handler. */

extern int SetIndexedSlot();

struct Sub {
    char _pad[0x60];
    unsigned short flags : 8;   /* 0x60 */
    unsigned short _bf : 8;
    char _pad2[0x1c7 - 0x62];
    signed char field_1c7;      /* 0x1c7 */
};

struct Obj {
    char _pad0[4];
    struct Sub **pp;            /* 0x04 */
    char _pad1[0x20 - 8];
    signed char field_20;      /* 0x20 */
};

void Ov166_AiStep_QueueAction1IfActive(struct Obj *this) {
    struct Sub *s = *this->pp;
    if (s->flags & 1) {
        s->field_1c7 = 1;
        SetIndexedSlot(this, this->field_20, 0);
    }
}
