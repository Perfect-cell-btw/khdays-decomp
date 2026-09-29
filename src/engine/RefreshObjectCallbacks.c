/* Runs an object's refresh callbacks: the update callback (+0x68) and the per-owner callback
 * (+0x78) with its owner. */

typedef void (*func_0203c7ac_cb1)(void *ptr, int arg);
typedef void (*func_0203c7ac_cb2)(void *ptr, int arg, int value);

void RefreshObjectCallbacks(void *pPtr, int arg) {
    int *ptr = (int *)pPtr;
    if (ptr[0x68 / 4] != 0) {
        ((func_0203c7ac_cb1)ptr[0x68 / 4])(ptr, arg);
    }

    if (ptr[0x78 / 4] != 0) {
        ((func_0203c7ac_cb2)ptr[0x78 / 4])(ptr, arg, ptr[0x84 / 4]);
    }
}
