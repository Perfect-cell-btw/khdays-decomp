/* True when the link context's stored player index (+0xa) is the running one. */

#include "game/engine.h"

extern int data_ov002_0207fa04;

int Ov002_IsLocalPlayerCurrent(void) {
    int ctx = *(int *)&data_ov002_0207fa04;
    return *(unsigned char *)(ctx + 0xa) == GetGlobalU16At6();
}
