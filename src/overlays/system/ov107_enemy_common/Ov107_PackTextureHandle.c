/* Packs the actor's texture VRAM address (+0x1a4, Actor.texAddr) and the caller's offset into a
 * texture handle. Its callers hold the actor as bytes, so it takes it so. */
unsigned Ov107_PackTextureHandle(char *obj, unsigned offset) {
    unsigned mask = 0xfffffc;
    unsigned addr = *(unsigned *)(obj + 0x1a4);
    if (addr == 0) {
        return 0;
    }
    return (((addr + 0x8000) & mask) << 7 | 0x80000000) | (offset & (mask >> 15));
}
