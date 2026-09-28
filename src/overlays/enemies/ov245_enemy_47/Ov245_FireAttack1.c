/* Ov245_FireAttack1 -- fire attack 1 on the owner, unless the guard byte at +0xad of the
 * node's parent says the actor is busy. */
extern void Ov107_PostTagUpdate(int owner, int a, int b);

void Ov245_FireAttack1(int self) {
    int *node = *(int **)(self + 4);
    if (*(unsigned char *)(node[1] + 0xad) != 0) {
        return;
    }
    Ov107_PostTagUpdate(node[0], 1, 0);
}
