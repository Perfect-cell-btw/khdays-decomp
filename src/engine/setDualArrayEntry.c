/* Stores a pair of values into two parallel global arrays. */

extern int data_0204bd88[];
extern int data_0204bd94[];
void setDualArrayEntry(int i, int v1, int v2) {
    data_0204bd88[i] = v1;
    data_0204bd94[i] = v2;
}
