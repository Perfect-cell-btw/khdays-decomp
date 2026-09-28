/* Calls the inner object's second virtual method. */

typedef void (*func_02030158_cb)(void *ptr, int value);

void Obj_InvokeInnerVtable4(int *ptr) {
    int *inner = (int *)ptr[6];
    func_02030158_cb cb = *(func_02030158_cb *)(inner[7] + 4);

    cb(inner + 2, 0);
}
