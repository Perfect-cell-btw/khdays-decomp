/* Sets the mode word (+0x70): 4 (clearing the timer) when the argument is set, 2 otherwise. */

void Ov267_SetMode70(char *obj, int arg) {
    if (arg) {
        *(int *)(obj + 0x44) = 0;
    }
    *(int *)(obj + 0x70) = arg ? 4 : 2;
}
