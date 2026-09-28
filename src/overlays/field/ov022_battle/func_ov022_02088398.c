extern short Session_GetLocalPlayerIndex(void);
extern int GetEntryField20ByIndex(int arg0);
extern int Ov022_ReceiveHit(int arg0, unsigned int *arg1);
int func_ov022_02088398(int arg0, unsigned int *arg1) {
    int e;
    if (Session_GetLocalPlayerIndex() != 0) return 0;
    e = GetEntryField20ByIndex(arg0);
    if (e != 0) return Ov022_ReceiveHit(e, arg1);
    return 0;
}
