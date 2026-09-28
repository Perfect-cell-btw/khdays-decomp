/* Sets the actor's pending action (+0x1c7). */

void Ov254_TwinMarker_QueueAction1(unsigned char **p) {
    p[0][0x1c7] = 1;
}
