/* Stores the value at tag tracker +0x28. */

void Ov002_TagTracker_SetField28(int unused, char *self, int value) { *(int *)(self + 0x28) = value; }
