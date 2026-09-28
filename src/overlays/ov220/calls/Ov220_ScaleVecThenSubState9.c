typedef struct Vec3 {
    int x;
    int y;
    int z;
} Vec3;

extern void ScaleVec3Fx12(int factor, void *src, void *dst);
extern void SetIndexedSlot(void *node, int idx, void *value);

void Ov220_ScaleVecThenSubState9(int node)
{
    int *state = *(int **)(node + 4);

    *(Vec3 *)((int)state + 0x24) = *(Vec3 *)((int)state + 0x30);
    ScaleVec3Fx12(0xb00, (void *)((int)state + 0x30), (void *)((int)state + 0x30));
    if (*(unsigned char *)(state[1] + 0xad) != 0) {
        return;
    }

    *(signed char *)(*state + 0x1c7) = 9;
    SetIndexedSlot((void *)node, *(signed char *)(node + 0x20), 0);
}
