extern void Ov148_BuildHeadingRotation();
extern void SetIndexedSlot();

struct w3 { int a, b, c; };

void Ov148_InvokeWithVec3ThenSetSubState5(int this_) {
    int node = *(int *)(this_ + 4);
    Ov148_BuildHeadingRotation(node, *(struct w3 *)(node + 0x28), 1);
    if (*(unsigned char *)(*(int *)(node + 4) + 0xad) != 0) return;
    *(signed char *)(*(int *)node + 0x1c7) = 5;
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), 0);
}
