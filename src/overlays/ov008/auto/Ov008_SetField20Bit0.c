void Ov008_SetField20Bit0(int unused, char *obj, unsigned val) {
    *(unsigned *)(obj + 0x20) = (*(unsigned *)(obj + 0x20) & ~1u) | (val & 1);
}
