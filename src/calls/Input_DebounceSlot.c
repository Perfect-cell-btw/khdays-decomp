/* Debounce slot `index`: bump its counter at +0xac and, once it reaches 16, flip
 * the slot's state at +0xb0 between 1 and 2, reset the counter and publish the
 * new state. The refresh at the end runs either way.
 *
 * The counter is RE-READ after the increment rather than held -- three separate
 * accesses to the same word. */
extern void SubObject_NudgeAndRedraw(void *panel, int index, int state);
extern void Gfx_EnqueueSurface(void *panel);

typedef struct {
    char pad0000[4];
    char *pCtx;     /* +4 */
} Root0204be08;

extern Root0204be08 data_0204be08;

void Input_DebounceSlot(int index) {
    char *ctx = data_0204be08.pCtx;
    int offset = index * 8;
    char *count = ctx + 0xac;

    *(int *)(count + offset) = *(int *)(count + offset) + 1;

    if (*(int *)(count + offset) >= 0x10) {
        int next;

        if (*(int *)(ctx + offset + 0xb0) == 1) {
            next = 2;
        } else {
            next = 1;
        }

        *(int *)(ctx + 0xb0 + offset) = next;
        *(int *)(count + offset) = 0;

        SubObject_NudgeAndRedraw(ctx + 0xc, index, *(int *)(ctx + 0xb0 + offset));
    }

    Gfx_EnqueueSurface(ctx + 0xc);
}
