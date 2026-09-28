extern void Ov002_TryBeginPanelRequest(void *req, int flag);
/* Build a 9-word request record on the stack (defaults 0 / -1) and submit it. The slot at [6] is
 * zeroed and then overwritten with `d`; the dead store survives because &req escapes. */
void Ov002_SubmitRequestRecord(int a, int b, int c, int d) {
    int req[9];
    req[0] = a;
    req[1] = b;
    req[2] = c;
    req[3] = 0;
    req[4] = 0;
    req[5] = -1;
    req[6] = 0;
    req[6] = d;
    Ov002_TryBeginPanelRequest(req, 0);
}
