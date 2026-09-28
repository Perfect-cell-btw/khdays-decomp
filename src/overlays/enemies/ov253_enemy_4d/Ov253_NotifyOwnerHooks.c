/* Ov253_NotifyOwnerHooks -- forward event 0 with the context's +0x20 block to the owner's +0x74
 * handler and event 9 to its +0x78 handler, each only when present. The handler is loaded after
 * the payload call (see 020d1cf0). */
extern int func_ov107_020c9848();
extern int func_ov022_02083f0c(void);

void Ov253_NotifyOwnerHooks(int self) {
    int ctx = *(int *)(self + 4);
    int obj;
    int arg;

    if (*(int *)(func_ov107_020c9848(self) + 0x74) != 0) {
        obj = func_ov107_020c9848();
        arg = func_ov022_02083f0c();
        (*(void (**)(int, int, int))(obj + 0x74))(arg, 0, ctx + 0x20);
    }
    if (*(int *)(func_ov107_020c9848() + 0x78) == 0) {
        return;
    }
    obj = func_ov107_020c9848();
    arg = func_ov022_02083f0c();
    (*(void (**)(int, int, int))(obj + 0x78))(arg, 9, 0);
}
