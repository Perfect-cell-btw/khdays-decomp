extern int GetEntryField20ByIndex(int arg0);
extern void Ov022_ApplyDamageAndFlagHit(int arg0, unsigned int arg1, int arg2);
void func_ov022_02088bec(int arg0, unsigned int arg1) {
    int e = GetEntryField20ByIndex(arg0);
    if (e == 0) return;
    Ov022_ApplyDamageAndFlagHit(e, arg1, 0);
}
