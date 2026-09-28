/* Offset param_3's two-int vector by Ov005_GetEntryBlock2c(param_1)'s vector and
 * forward the sum (on the stack) to Ov005_ReleaseTwoSlotsEx with param_2. */
struct vec2_020548bc { int x, y; };
extern struct vec2_020548bc *Ov005_GetEntryBlock2c(int obj, int b);
extern void Ov005_ReleaseTwoSlotsEx(int obj, int arg, struct vec2_020548bc *sum);

void Ov005_ApplyOffsetSum(int param_1, int param_2, struct vec2_020548bc *param_3) {
    struct vec2_020548bc sum;
    struct vec2_020548bc *v = Ov005_GetEntryBlock2c(param_1, param_2);
    sum.x = param_3->x + v->x;
    sum.y = param_3->y + v->y;
    Ov005_ReleaseTwoSlotsEx(param_1, param_2, &sum);
}
