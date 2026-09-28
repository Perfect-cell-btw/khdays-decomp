/* Dispatches the message to the handler at +0x1c.  Messages whose byte at +2 is zero are
 * gated on Session_GetLocalPlayerIndex first; a missing handler is not an error. */
extern int Session_GetLocalPlayerIndex(int a);

void Ov107_DispatchMessage(char *self, unsigned char *msg, int arg) {
    void (*fn)(char *, unsigned char *, int);
    if (msg[2] == 0) {
        if (Session_GetLocalPlayerIndex((int)self) == 0) {
            return;
        }
    }
    fn = *(void (**)(char *, unsigned char *, int))(self + 0x1c);
    if (fn == 0) {
        return;
    }
    fn(self, msg, arg);
}
