/* Pops a free request slot from the loader's free list, or NULL. */

extern int gFileLoader[];

int *Loader_PopFreeRequest(void)
{
    int *p = (int *)gFileLoader[0x18 / 4];

    if (p != 0) {
        gFileLoader[0x18 / 4] = p[0];
        p[0] = 0;
    }
    return p;
}
