/* Returns 1 when bit 1 is set, 0 when bit 2 is set, otherwise the pointer itself. */

unsigned int * Ov022_ComboStateOpenOrSelf(unsigned int *arg0) {
    if ((*arg0 & 2) != 0) return (unsigned int *)1;
    if ((*arg0 & 4) != 0) return (unsigned int *)0;
    return arg0;
}
