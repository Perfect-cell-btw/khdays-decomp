extern int QueryActiveStateOrDelegate(void);
extern void MsgQueue_SendGate(int arg0, unsigned short *arg1, int arg2);

struct marshal_02094810 {
    unsigned char lo2 : 2;
    unsigned char mid3 : 3;
    unsigned char hi3 : 3;
    unsigned char b1;
};

void func_ov022_02094810(int param_1, unsigned char param_2) {
    struct marshal_02094810 m;
    m.lo2 = *(unsigned char *)(*(int *)(param_1 + 0x328) + 9);
    m.mid3 = (unsigned char)QueryActiveStateOrDelegate();
    m.hi3 = 5;
    m.b1 = param_2;
    MsgQueue_SendGate(0x10, (unsigned short *)&m, 2);
}
