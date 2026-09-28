/* Whether bit 0 of the byte is set. */

int Ov022_IsReactionActive(unsigned char *p) {
    return (*p & 1) > 0;
}
