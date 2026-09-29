/* Free the heap block pointed at by the object's third word (+8) through
 * NNSi_FndFreeFromDefaultHeap, if it is non-null. Does not clear the field. */

extern int NNSi_FndFreeFromDefaultHeap();

void FreeFieldAt8(char *pP) {
    int *p = (int *)pP;
    int a = p[2];
    if (a) {
        NNSi_FndFreeFromDefaultHeap(a);
    }
}
