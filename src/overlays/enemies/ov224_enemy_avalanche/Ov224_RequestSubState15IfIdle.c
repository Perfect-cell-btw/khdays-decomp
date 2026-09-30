/* Reaction check: queues action 15 when no action is pending; returns whether it did. */

int Ov224_RequestSubState15IfIdle(char *arg0) {
    signed char *p = **(signed char ***)(arg0 + 0x214);
    if (p[0x1c7] == -1) {
        p[0x1c7] = 0xf;
        return 1;
    }
    return 0;
}
