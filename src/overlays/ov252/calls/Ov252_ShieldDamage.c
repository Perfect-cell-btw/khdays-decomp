/* Shield damage of the ov252 actor: the hit's damage (020c89e8, into +0x28) comes off the shield
 * (+0x8e, at least 0) and whatever the shield did not absorb comes off the actor's health (+0x21a).
 * Returns 0 while the shield holds; when it breaks it regenerates to a ninth of the maximum health
 * (+0x218) and 1 is returned. */
extern int Ov107_CalcHitDamage(char *self, char *hit);

int Ov252_ShieldDamage(char *shield, char *hit, char *self)
{
    short old = *(short *)(shield + 0x8e);

    *(int *)(hit + 0x28) = Ov107_CalcHitDamage(self, hit);
    *(short *)(shield + 0x8e) -= *(int *)(hit + 0x28);
    if (*(short *)(shield + 0x8e) <= 0) {
        *(short *)(shield + 0x8e) = 0;
    }
    *(short *)(self + 0x21a) -= old - *(short *)(shield + 0x8e);
    if (*(short *)(shield + 0x8e) != 0) {
        return 0;
    }
    *(short *)(shield + 0x8e) = *(short *)(self + 0x218) / 9;
    return 1;
}
