/* Marshal an 8-byte link message: the local player's slot in the low 2 bits, the
 * link layer's own id in the next 3, message kind 4 in the top 3, and the
 * caller's word at +4. Sent on channel 0x10.
 *
 * Sibling of func_ov022_02094810 -- same bitfield header, wider payload (a word
 * at +4 rather than a byte at +1) and therefore an 8-byte frame. */
extern int QueryActiveStateOrDelegate(void);
extern void MsgQueue_SendGate(int channel, unsigned short *message, int size);

struct marshal_020947a4 {
    unsigned char lo2 : 2;
    unsigned char mid3 : 3;
    unsigned char hi3 : 3;
    unsigned char pad1[3];
    int w4;
};

void Ov022_SendPayloadMessage(int self, int payload) {
    struct marshal_020947a4 m;

    m.lo2 = *(unsigned char *)(*(int *)(self + 0x328) + 9);
    m.mid3 = (unsigned char)QueryActiveStateOrDelegate();
    m.hi3 = 4;
    m.w4 = payload;

    MsgQueue_SendGate(0x10, (unsigned short *)&m, 8);
}
