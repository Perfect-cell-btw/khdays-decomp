/* Tail-call Scene_RequestPending with fixed args (0xb, 0). */
extern int Scene_RequestPending(int a, int b);
int Ov000_RequestScene11(void) {
    return Scene_RequestPending(0xb, 0);
}
