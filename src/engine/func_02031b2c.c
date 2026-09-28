/* Returns 1 when the object's mode (+0x4604) is 1, 2 when it is 2, and the argument otherwise. */

int func_02031b2c(int arg0) {
    if (*(int *)(arg0 + 0x4604) != 1) {
        if (*(int *)(arg0 + 0x4604) == 2) arg0 = 2;
        return arg0;
    }
    return 1;
}
