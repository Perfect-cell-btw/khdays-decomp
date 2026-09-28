/* Offset param_3's two-int vector by Ov008_GetEntryBlock2c(param_1)'s vector and
 * forward the sum (on the stack) to Ov008_SetEntryPos with param_2. */
struct vec2_020548bc { int x, y; };
extern struct vec2_020548bc *Ov008_GetEntryBlock2c(int obj, int b);
extern void Ov008_SetEntryPos(int obj, int arg, struct vec2_020548bc *sum);

void Ov008_ApplyOffsetSum(int param_1, int param_2, struct vec2_020548bc *param_3) {
    struct vec2_020548bc sum;
    struct vec2_020548bc *v = Ov008_GetEntryBlock2c(param_1, param_2);
    sum.x = param_3->x + v->x;
    sum.y = param_3->y + v->y;
    Ov008_SetEntryPos(param_1, param_2, &sum);
}
