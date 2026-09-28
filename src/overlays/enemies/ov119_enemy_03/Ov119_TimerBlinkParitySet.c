/*
 * Ov119_TimerBlinkParitySet -- x3. Twin of Ov119_TimerBlinkParityClear: advance a timer, blink a flag by counter
 * parity, dispatch -- but the once-past branch SETS bit1 of *(*(state[0]+0x384))+0x5c (|= 2) instead
 * of clearing it. state[1] += owner_delta; FX_Inv(state[1], 0x1000) (result unused); state[2]++ and
 * write its parity into bit1. While state[1] < 0x800 return. Once past: set bit1, hand off 0203c640.
 */
extern int  FX_Div(int x, int k);
extern void Task_MarkFinished(int self);

void Ov119_TimerBlinkParitySet(int *self) {
    int *state = (int *)self[1];
    int q;

    state[1] += *(int *)(*self + 0x2c);
    FX_Div(state[1], 0x1000);
    state[2] += 1;
    q = *(int *)(*state + 0x384);
    *(int *)(q + 0x5c) = (*(int *)(q + 0x5c) & ~2) | ((unsigned int)(state[2] << 0x1f) >> 0x1e);
    if (state[1] < 0x800) {
        return;
    }
    q = *(int *)(*state + 0x384);
    *(int *)(q + 0x5c) |= 2;
    Task_MarkFinished((int)self);
}
