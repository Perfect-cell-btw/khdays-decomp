/* Ov105_TerminateOnState8 -- fatal-check the scene state, ov105. When the scene reaches
 * error state 8, logs code 9 (Ov105_SetField24) and terminates. */
extern void Ov105_SetField24(int);
extern void OS_Terminate(void);
void Ov105_TerminateOnState8(char *scene) {
    if (*(unsigned short *)(scene + 2) == 8) {
        Ov105_SetField24(9);
        OS_Terminate();
    }
}
