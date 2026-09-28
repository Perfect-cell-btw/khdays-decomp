extern void Ov256_RotateByActorHeading(void *out, int self, int arg);
extern int Ov107_PostTagUpdate(int, int, int);
extern int Ov107_StartAnim(int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov256_FlightTick(int);
struct w3 { int a, b, c; };
void Ov256_AiTakeOff(int param_1) {
    int owner = *(int *)(param_1 + 4);
    struct w3 buf;
    Ov256_RotateByActorHeading(&buf, param_1, *(int *)(*(int *)owner + 0x450) + 0x2c);
    *(struct w3 *)(owner + 0x10) = buf;
    if (*(unsigned char *)(*(int *)(owner + 4) + 0xad) != 0) return;
    Ov107_PostTagUpdate(*(int *)owner, 3, 0);
    Ov107_StartAnim(*(int *)(*(int *)owner + 0x450), 2, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov256_FlightTick);
}
