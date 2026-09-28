/* Clears the two active handler slots. */

extern int data_ov025_020b574c;

void Ov025_ClearActiveHandlers(void) {
    *(int *)&data_ov025_020b574c = -1;
    *(int *)((char *)&data_ov025_020b574c + 4) = -1;
}
