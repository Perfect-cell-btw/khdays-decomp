/* Set the task's finished flag (+0x24 = 1), null-safe. Step functions call this on every terminal
 * branch, versus SetIndexedSlot(task, task[0x20], next_step) to continue -- see
 * Ov107_SoundFollowTick, which does exactly one or the other. */

void Task_MarkFinished(int *p) {
    if (p) {
        p[9] = 1;
    }
}
