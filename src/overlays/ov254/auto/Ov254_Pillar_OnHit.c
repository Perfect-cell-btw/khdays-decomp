/* Message hook: when bit 4 of the message's first halfword is set, raises the ready word at
 * +0x4e0 of the object reached through ctx -> +0x390.
 *
 * The function is NOT void -- the ROM never reuses r0, which only makes sense if `self` is
 * still the return value at both exits; as a void function mwcc colours everything one
 * register lower. */
char *Ov254_Pillar_OnHit(char *self, int unused, unsigned int *msg) {
    char *ctx = *(char **)(self + 0x214);
    if (((unsigned short)*msg & 0x10) == 0) {
        return self;
    }
    *(int *)(*(char **)(*(char **)ctx + 0x390) + 0x4e0) = 1;
    return self;
}
