/* False when obj+4 is not 10. For sub-kinds 5 and 10 it is also false once bit 16 of the 64-bit
 * flag word at obj[0x328]+0x464 is set. True otherwise. */

struct Flags020955b0 { char pad0[0x464]; unsigned long long flags; };

int Ov022_IsActionAllowed(int arg0) {
    int base = *(int *)(arg0 + 0x328);
    int t;
    if (*(int *)(arg0 + 4) != 10) goto zero;
    t = *(int *)(base + 0xc);
    if (t != 5 && t != 10) goto one;
    if ((((struct Flags020955b0 *)base)->flags & 0x10000LL) != 0) return 0;
one:
    return 1;
zero:
    return 0;
}
