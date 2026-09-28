typedef struct {
    int x;
    int y;
    int z;
} func_0202b450_vec;

extern void Node_SetPosAndNotify(void *ptr);

void Actor_SetVecAndSyncChild(int *ptr, func_0202b450_vec *src) {
    if ((ptr[0] & 0x10) == 0) {
        Node_SetPosAndNotify((char *)ptr + 0x110);
    }

    *(func_0202b450_vec *)((char *)ptr + 0xa8) = *src;
}
