/* Reaction check: starts a fixed sub-state as the pending action (+0x1c7) when no action is
 * pending; returns whether it did. */

struct substate { signed char _pad[0x1c7]; signed char status; };
int Ov155_TryBeginSubState4(int obj)
{
    struct substate *state = *(struct substate **)(*(int *)(obj + 0x214));
    if (state->status == -1) { state->status = 4; return 1; }
    return 0;
}
