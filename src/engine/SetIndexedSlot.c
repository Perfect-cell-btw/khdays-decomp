/* Stores a callback in an AI task's step slot `i` (the step callbacks start at +8, see
 * game/ai_task.h). Returns the address a + i as a number: the ROM leaves it in r0, and the AI steps
 * that end by tail-calling this return it as their (non-zero) result. */

int SetIndexedSlot(int *a, int i, int v)
{
    a += i;
    a[2] = v;
    return (int)a;
}
