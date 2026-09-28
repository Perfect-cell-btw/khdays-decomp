/* Sets bit 0 of the element's flag word (+0x20) from the value. */

void Ov025_SetField20Bit0(int unused, char *obj, unsigned val) {
    *(unsigned *)(obj + 0x20) = (*(unsigned *)(obj + 0x20) & ~1u) | (val & 1);
}
