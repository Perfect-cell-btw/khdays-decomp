/* Reaction check: requests a fixed sub-state as the pending action (+0x1c7) when no action is
 * pending; returns whether it did. */

struct actor_status { signed char _pad[0x1c7]; signed char status; };

int Ov286_TryBeginSubState5IfIdle(int this_) {
    int state = **(int **)(this_ + 0x214);
    if (((struct actor_status *)state)->status == -1) {
        ((struct actor_status *)state)->status = 5;
        return 1;
    }
    return 0;
}
