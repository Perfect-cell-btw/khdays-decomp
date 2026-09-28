/* Clears a record's first two words and its counters at +0x334..+0x337. */

void Ov022_ClearFields(unsigned int *arg0) {
    arg0[0] = 0;
    arg0[1] = 0;
    *(unsigned char *)((int)arg0 + 0x334) = 0;
    *(unsigned short *)((int)arg0 + 0x336) = 0;
    *(unsigned char *)((int)arg0 + 0x335) = 0;
}
