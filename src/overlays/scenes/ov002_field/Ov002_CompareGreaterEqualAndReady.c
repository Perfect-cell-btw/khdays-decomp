/* Whether a >= b and the ready flag is set. */

int Ov002_CompareGreaterEqualAndReady(int arg0, int arg1, int arg2) {
    if (arg0 >= arg1 && arg2 != 0) {
        return 1;
    }
    return 0;
}
