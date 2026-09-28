/* Copy the child's +0x18 vector into *(child)+0xf0. */
struct w3 { int a, b, c; };
void Ov226_AiApplyMoveVector(int param_1) {
    int child = *(int *)(param_1 + 4);
    *(struct w3 *)(*(int *)child + 0xf0) = *(struct w3 *)(child + 0x18);
}
