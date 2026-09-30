/* Returns the aim node's state word (+0x50). */

int Ov201_GetState(char *self) { return *(int *)(self + 0x50); }
