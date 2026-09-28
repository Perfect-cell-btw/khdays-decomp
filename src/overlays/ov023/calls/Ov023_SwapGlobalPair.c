/* Swap the two shared global words. */
extern int data_0204c024;
extern int data_0204c02c;
void Ov023_SwapGlobalPair(void) {
    int tmp = data_0204c024;
    data_0204c024 = data_0204c02c;
    data_0204c02c = tmp;
}
