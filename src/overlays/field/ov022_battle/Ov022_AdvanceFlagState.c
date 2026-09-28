/* Advances a flag state: bit 0 adds bit 2; otherwise bit 1 clears the state and its counter. */

void Ov022_AdvanceFlagState(unsigned char *arg0) {
    unsigned char v = *arg0;
    if ((v & 1) != 0) {
        *arg0 = v | 4;
        return;
    }
    if ((v & 2) != 0) {
        *arg0 = 0;
        arg0[3] = 0;
    }
}
