/* Written as a ternary, not `a && b`: the && form makes mwcc branch over the second
 * test, while the ROM predicates it (moveq/movne). */
extern int Ov022_IsBit0Set_5(unsigned char *arg0);
int Ov022_IsActiveAndCountPositive(unsigned char *arg0) {
    return Ov022_IsBit0Set_5(arg0) == 0 ? 0 : *(int *)(arg0 + 0x110) > 0;
}
