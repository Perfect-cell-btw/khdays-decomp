extern void Ov238_SetPendingState2(int target);
/* Raise the "done" flag (+0x390); when the actor is in state 1, notify its sub-target (+0x214). */
void Ov238_FlagDoneAndNotify(int obj) {
    *(int *)(obj + 0x390) = 1;
    if (*(int *)(obj + 0x50) != 1) {
        return;
    }
    Ov238_SetPendingState2(*(int *)(obj + 0x214));
}
