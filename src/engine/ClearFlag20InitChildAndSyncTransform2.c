/* Binds an animation sequence to the node: clears flag 0x20, registers the sequence on the child
 * and, when flag 8 is set, restores the saved position; always returns 1. */

extern void StoreField74ThenForward();

struct vec3 { int x, y, z; };

int ClearFlag20InitChildAndSyncTransform2(int this_, int arg1, int arg2, int arg3) {
    if (arg1 != 0) {
        *(int *)this_ &= ~0x20;
        StoreField74ThenForward(this_ + 4, arg1, arg2, arg3);
        if (*(int *)this_ & 8) {
            *(struct vec3 *)(this_ + 0xa8) = *(struct vec3 *)(this_ + 0x13c);
        }
    }
    return 1;
}
