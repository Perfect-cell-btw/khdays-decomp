/* Applies the orientation quaternion and the pending velocity to the item. */

struct w3 { int a, b, c; };
extern int Srt_SetRotationQuat(int dst, int src);
extern const struct w3 data_02041dc8;

void Ov260_Item_ApplyOrientation(int param_1) {
    int child = *(int *)(param_1 + 4);
    Srt_SetRotationQuat(*(int *)child + 0xa0, child + 8);
    {
        struct w3 *p = (struct w3 *)(child + 0x28);
        *(struct w3 *)(*(int *)child + 0xf0) = *p;
        *p = data_02041dc8;
    }
}
