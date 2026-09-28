/* Clears the object's pointer when it points to an entry of type 0x15; returns whether it did. */

int Ov008_ClearPtrIfType15(char *obj) {
    if (*(unsigned short *)(*(int *)obj + 2) != 0x15) {
        return 0;
    }
    *(int *)obj = 0;
    return 1;
}
