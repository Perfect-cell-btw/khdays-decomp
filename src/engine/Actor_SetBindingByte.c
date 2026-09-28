/* Stores a byte into the actor's binding table (+0x24) at the index. */

void Actor_SetBindingByte(char *p, int i, char v) {
    char *q = p + i;
    q[0x24] = v;
}
