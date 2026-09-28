/* Whether the record's handler table (+0x1c) is a given mode's table. */

extern int data_02042910;

int IsField1cEqualData42910(int arg0) {
    return *(int *)(arg0 + 0x1c) == (int)&data_02042910;
}
