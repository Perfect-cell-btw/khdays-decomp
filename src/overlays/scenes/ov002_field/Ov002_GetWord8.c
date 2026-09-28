/* Returns the word at a fixed offset of the object. */

int Ov002_GetWord8(char *self) { return *(int *)(self + 0x8); }
