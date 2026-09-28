/* Returns the number of players in the local player mask (func_01ff8138). */

extern int func_01ff8138(void);
extern int Ov008_CountPlayersInMask(short *);
int Ov008_CountLocalPlayers(void)
{
    short mask = func_01ff8138();
    return Ov008_CountPlayersInMask(&mask);
}
