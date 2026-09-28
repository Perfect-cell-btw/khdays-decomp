/* Runs the element's close callback (+0x40) when asked to and one is installed, then marks the
 * element inactive (+0x14 = 0). */

struct A {
    char pad[0x40];
    void (*fn)(void *);
};

void Ov008_InvokeElementCallback(struct A *a, void *b, int c) {
    if (c != 0 && a->fn != 0) {
        a->fn(b);
    }
    *(int *)((char *)b + 0x14) = 0;
}
