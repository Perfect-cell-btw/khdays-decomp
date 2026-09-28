/* Reaction check: queues action 7 unless it is already the current action; returns whether it did.
 */

int Ov214_RequestSubState7IfNotCurrent(int *r0) {
    signed char *r1 = (signed char *)((int *)r0[0x214 / 4])[0];
    if (r1[0x1c6] != 7) {
        r1[0x1c7] = 7;
        return 1;
    }
    return 0;
}
