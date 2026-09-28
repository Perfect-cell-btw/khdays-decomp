/* AI step: once the actor is active, points the step at its current waypoint, makes the stored
 * action pending and clears the step handler. */

struct hw60 { unsigned short lo : 8, hi : 8; };
extern void SetIndexedSlot();

void Ov242_SetField1cFromMlaThenAdvance(int this_) {
    int holder = *(int *)(this_ + 4);
    if ((((struct hw60 *)(*(int *)holder + 0x60))->lo & 1) == 0) return;
    *(int *)(holder + 0x1c) = *(int *)(holder + 0x24) * 0x14 + *(int *)(*(int *)holder + 0x3a4);
    *(signed char *)(*(int *)holder + 0x1c7) = *(signed char *)(*(int *)holder + 0x1c9);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), 0);
}
