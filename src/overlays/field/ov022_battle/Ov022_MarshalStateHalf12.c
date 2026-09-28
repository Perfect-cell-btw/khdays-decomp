/* Sends a player state message (kind 0xc) with the local player, the entry's group and the value.
 * Returns the queued message's handle.
 */

extern int QueryActiveStateOrDelegate(void);
extern unsigned short func_02031384(int a, void *buf, int c);

struct Buf0208a464 {
    unsigned short f0 : 3;
    unsigned short f3 : 2;
    unsigned short f5 : 5;
    unsigned short f10 : 3;
    unsigned short rest : 3;
};

unsigned short Ov022_MarshalStateHalf12(int obj, int param_2, int *param_3) {
    int e = *(int *)(obj + 0x58);
    struct Buf0208a464 buf;
    buf.f0 = (unsigned short)QueryActiveStateOrDelegate();
    buf.f3 = *(unsigned char *)(e + 9);
    buf.f10 = (unsigned short)param_2;
    if (param_2 == 0) buf.f5 = *param_3;
    return func_02031384(0xc, &buf, 4);
}
