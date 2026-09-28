/* Sets the actor's position (+0xa8), first notifying its node of the move unless the actor is
 * detached (flag 0x10). */

typedef struct {
    int x;
    int y;
    int z;
} func_0202b450_vec;

extern void Node_SetPosAndNotify(void *ptr, void *src);

void Actor_SetVecAndSyncChild(int *ptr, func_0202b450_vec *src) {
    if ((ptr[0] & 0x10) == 0) {
        Node_SetPosAndNotify((char *)ptr + 0x110, src);
    }

    *(func_0202b450_vec *)((char *)ptr + 0xa8) = *src;
}
