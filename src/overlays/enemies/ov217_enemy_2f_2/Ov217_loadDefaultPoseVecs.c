/* Resets the tracked position and movement vectors to zero and starts the child's animation. */

struct v3 { int a, b, c; };
extern void SetSubitemState(void *p, int a, int b, int c);
extern int data_02041dc8[];

void Ov217_loadDefaultPoseVecs(char *this, int param2) {
    struct v3 buf = *(struct v3 *)data_02041dc8;
    *(struct v3 *)(this + 0x3b4) = buf;
    *(struct v3 *)(this + 0x424) = buf;
    SetSubitemState(*(void **)(this + 0x420), 0, (short)param2, 0);
}
