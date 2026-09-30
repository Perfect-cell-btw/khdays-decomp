/* Publishes the step velocity to the actor's movement vector (+0xf0), zeroing it first outside
 * action 2. */

extern int data_02041dc8;

struct w3 { int a, b, c; };

void Ov287_StageVecUnlessState2ThenCommit(int this_) {
    int node = *(int *)(this_ + 4);
    if (*(signed char *)(*(int *)node + 0x1c6) != 2) {
        *(struct w3 *)(node + 0x1c) = *(struct w3 *)&data_02041dc8;
    }
    *(struct w3 *)(*(int *)node + 0xf0) = *(struct w3 *)(node + 0x1c);
}
