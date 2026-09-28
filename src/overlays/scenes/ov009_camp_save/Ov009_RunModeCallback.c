/* Ov009_RunModeCallback -- dispatch the current menu command, ov009. Looks up the handler
 * for the active command (Ov009_GetCtxField95cc) in the jump table data_ov009_02055f88 and
 * calls it if present. */
extern int Ov009_GetCtxField95cc(void);
extern void (*data_ov009_02055f88[])(void);
void Ov009_RunModeCallback(void) {
    void (*handler)(void) = data_ov009_02055f88[Ov009_GetCtxField95cc()];
    if (handler != 0) {
        handler();
    }
}
