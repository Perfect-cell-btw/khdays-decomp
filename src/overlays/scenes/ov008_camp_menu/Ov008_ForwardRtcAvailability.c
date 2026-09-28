/* Feeds the local key state to the menu's input handler. */

extern int func_01ff8138(void);
extern void Ov008_CountPlayersInMask(short *);
void Ov008_ForwardRtcAvailability(void)
{
    short value = func_01ff8138();
    Ov008_CountPlayersInMask(&value);
}
