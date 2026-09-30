/* Sets the state word (+0x6c) to 1 and clears the mode (+0x70 = -1). */

void Ov267_SetState6cReset70(char *obj) {
    *(int *)(obj + 0x6c) = 1;
    *(int *)(obj + 0x70) = -1;
}
