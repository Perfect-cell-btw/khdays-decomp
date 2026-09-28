/* Whether the session is live and the local actor and its target are valid, with the target's flag
 * set. */

extern int Ov002_PollSession(void);
extern int func_ov022_02083f0c(void);
extern int func_ov022_02083f5c(void);
extern int Ov002_GetBit0OfField38IfValid(int arg0);

int func_ov022_02087344(void) {
    int a;
    if (Ov002_PollSession() == 0) return 0;
    a = func_ov022_02083f0c();
    if (a == -1) return 0;
    if (func_ov022_02083f5c() == -1) return 0;
    return Ov002_GetBit0OfField38IfValid(a) != 0;
}
