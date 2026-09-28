/* Call Ov002_SwapActivePair(param_1, param_2) only when the global at
 * data_ov002_0207f9f0 is set. */
extern void Ov002_SwapActivePair(int a, int b);
extern int data_ov002_0207f9f0;

void Ov002_SwapActivePairIfActive(int param_1, int param_2) {
    if (*(int *)&data_ov002_0207f9f0 != 0) {
        Ov002_SwapActivePair(param_1, param_2);
    }
}
