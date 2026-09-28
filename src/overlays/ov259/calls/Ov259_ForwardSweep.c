/* Forward a body sweep of the ov259 actor to its +0x214 rig while it is live (+0x50 == 1). */
typedef struct { int x, y, z; } Vec3;

extern void Ov259_RequestMoveTo(int rig, int a, int b, Vec3 lift);

void Ov259_ForwardSweep(char *self, int a, int b, Vec3 lift)
{
    if (*(int *)(self + 0x50) != 1) {
        return;
    }
    Ov259_RequestMoveTo(*(int *)(self + 0x214), a, b, lift);
}
