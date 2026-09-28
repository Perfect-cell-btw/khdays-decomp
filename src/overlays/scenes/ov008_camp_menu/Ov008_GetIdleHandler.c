/* Ticks the card transfer scene; returns the idle handler once the link is done, otherwise none. */

extern char *data_ov008_02090f24;
extern void Ov008_TickCardTransferScene(void);
extern void Ov008_IdleHandlerNoOp(void);

void (*Ov008_GetIdleHandler(void))(void)
{
    void (*callback)(void) = 0;

    Ov008_TickCardTransferScene();
    if (*(int *)(data_ov008_02090f24 + 0x49c) == 0) {
        callback = Ov008_IdleHandlerNoOp;
    }

    return callback;
}
