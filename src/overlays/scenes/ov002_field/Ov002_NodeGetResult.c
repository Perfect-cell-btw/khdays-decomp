/* Returns a node's result byte (+0x10). */

int Ov002_NodeGetResult(char *self) { return *(signed char *)(self + 0x10); }
