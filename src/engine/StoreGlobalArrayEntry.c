/* Stores a word into a global array. */

extern int data_020425ec;

void StoreGlobalArrayEntry(int index, int value) {
    ((int *)&data_020425ec)[index] = value;
}
