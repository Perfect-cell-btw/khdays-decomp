/* Whether the word the second argument points to is zero. */

int IsDerefZero(int arg0, int *arg1) {
    return *arg1 == 0;
}
