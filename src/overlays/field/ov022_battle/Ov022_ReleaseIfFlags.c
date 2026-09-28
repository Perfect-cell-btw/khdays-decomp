/* Advances the flag state of the attached record when bit 0 or 1 of the byte at +9 is set. */

extern void Ov022_AdvanceFlagState();
void Ov022_ReleaseIfFlags(unsigned int *arg0) {
    if ((*(unsigned char *)((int)arg0 + 9) & 2) != 0 || (*(unsigned char *)((int)arg0 + 9) & 1) != 0)
        Ov022_AdvanceFlagState((unsigned char *)*arg0);
}
