/* Returns the number of players in the local player mask (func_01ff8138). */

extern int func_01ff8138(void);
extern int Ov006_CountPlayersInMask(short *p);
int Ov006_CountLocalPlayers(void) {
    short mask = func_01ff8138();
    return Ov006_CountPlayersInMask(&mask);
}
