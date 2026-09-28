/* Stores the position, marks it dirty and calls the node's change hook. */

typedef struct {
    int x;
    int y;
    int z;
} func_020293fc_vec;

typedef void (*func_020293fc_cb)(void *ptr);

void Node_SetPosAndNotify(unsigned char *ptr, func_020293fc_vec *src) {
    func_020293fc_cb cb;

    *(func_020293fc_vec *)(ptr + 0x2c) = *src;
    ptr[0x20] |= 1;

    cb = *(func_020293fc_cb *)*(int *)(ptr + 0x1c);
    if (cb != 0) {
        cb(ptr);
    }
}
