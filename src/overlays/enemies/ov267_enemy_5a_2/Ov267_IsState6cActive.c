/* Tests the object's state word (+0x6c) against the states that allow the check. */

int Ov267_IsState6cActive(char *obj, int arg) {
    if (arg == 0) {
        if ((unsigned)(*(int *)(obj + 0x6c) - 2) <= 1) {
            return 1;
        }
    }
    return *(int *)(obj + 0x6c) == 1;
}
