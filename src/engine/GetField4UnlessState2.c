/* Returns the record's value (+4), or 0 when its state is 2. */

int GetField4UnlessState2(int arg0) {
    return (*(short *)arg0 == 2) ? 0 : *(int *)(arg0 + 4);
}
