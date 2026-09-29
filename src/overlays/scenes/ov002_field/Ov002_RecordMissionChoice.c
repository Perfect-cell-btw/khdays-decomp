#include "game/engine.h"

extern int Ov002_RunShutdownHook(void);
extern int func_ov002_0206373c(void);
extern void Ov002_ClearCharBlock(int);
extern char *data_ov002_0207f99c;

/* Confirms the pending mission once the fade is done, and records the caller's choice when the
 * current slot is the local player's. */
void Ov002_RecordMissionChoice(int choice) {
    char *self = data_ov002_0207f99c;
    if (Ov002_RunShutdownHook() != 0) {
        return;
    }
    Ov002_ClearCharBlock(func_ov002_0206373c());
    if (*(int *)(self + 4) == Session_GetLocalPlayerIndex()) {
        *(int *)(self + 0x28) = choice;
    }
}
