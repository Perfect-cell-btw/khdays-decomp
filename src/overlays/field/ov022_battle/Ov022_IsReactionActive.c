int Ov022_IsReactionActive(unsigned char *p) {
    return (*p & 1) > 0;
}
