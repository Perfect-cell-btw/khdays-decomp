unsigned int * Ov022_ComboStateOpenOrSelf(unsigned int *arg0) {
    if ((*arg0 & 2) != 0) return (unsigned int *)1;
    if ((*arg0 & 4) != 0) return (unsigned int *)0;
    return arg0;
}
