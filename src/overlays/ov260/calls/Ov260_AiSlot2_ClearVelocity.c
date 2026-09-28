/* Copy a const 3-word vector into *(child)+0xf0. */
struct w3 { int a, b, c; };
extern int data_02041dc8;
void Ov260_AiSlot2_ClearVelocity(int param_1) {
    *(struct w3 *)(*(int *)(*(int *)(param_1 + 4)) + 0xf0) = *(struct w3 *)&data_02041dc8;
}
