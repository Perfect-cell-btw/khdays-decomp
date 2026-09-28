/* Whether bit 0 of the byte is set. */

int Ov022_IsBit0Set_5(unsigned char *p) {
    return (*p & 1) > 0;
}
