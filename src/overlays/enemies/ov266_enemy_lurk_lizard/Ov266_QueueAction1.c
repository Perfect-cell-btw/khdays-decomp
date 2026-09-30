/* Sets the actor's pending action (+0x1c7). */

void Ov266_QueueAction1(unsigned char **p) {
    p[0][0x1c7] = 1;
}
