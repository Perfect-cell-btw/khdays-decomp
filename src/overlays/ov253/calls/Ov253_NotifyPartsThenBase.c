/* Runs the two per-slot hooks (+0x1ec then +0x1f0) over the four objects in the table at
 * +0x458, after letting Ov107_AiState_LoadStats refresh them.
 *
 * The first hook's argument is read out of +0x19d BEFORE the null check -- the ROM's
 * `ldrb r1,[r6,#0x19d]` sits above the branch, not inside it. */
extern void Ov107_AiState_LoadStats(char *self);

void Ov253_NotifyPartsThenBase(char *self) {
    int i;
    int five;
    void (*f)(char *, int);
    char *o;
    int arg;
    Ov107_AiState_LoadStats(self);
    i = 0;
    five = 5;
    do {
        o = (*(char ***)(self + 0x458))[i];
        arg = *(unsigned char *)(self + 0x19d);
        f = *(void (**)(char *, int))(o + 0x1ec);
        if (f != 0) {
            f(o, arg);
        }
        o = (*(char ***)(self + 0x458))[i];
        f = *(void (**)(char *, int))(o + 0x1f0);
        if (f != 0) {
            f(o, five);
        }
        i = i + 1;
    } while (i < 4);
}
