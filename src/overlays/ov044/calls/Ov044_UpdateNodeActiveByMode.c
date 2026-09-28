/* Deactivates the node outside modes 0x2f/0x30, then updates it while active. */

extern int Anim_SetFrameWrapped(int, int, int);
extern int Anim_GetFrame(int, int);

void Ov044_UpdateNodeActiveByMode(int r0) {
    int r4 = r0;
    int r1 = *(int *)(r4 + 0xdb4);
    int v = *(int *)(r1 + 0x6bc);
    int n;

    if (v != 0x2f && v != 0x30) {
        if (*(int *)(r4 + 0x124) != 0) {
            *(int *)(r4 + 0x124) = 0;
        }
    }

    if (*(int *)(r4 + 0x124) != 1) {
        return;
    }

    n = Anim_GetFrame(*(int *)(r1 + 0x20) + 4, 0);
    if (n <= 0x1000) {
        return;
    }

    Anim_SetFrameWrapped(r4 + 0x128, 0, n - 0x1000);
    Anim_SetFrameWrapped(r4 + 0x128, 2, n - 0x1000);
    Anim_SetFrameWrapped(r4 + 0x128, 1, n - 0x1000);
}
