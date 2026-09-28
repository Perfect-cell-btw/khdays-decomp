extern void Entity_Register(int, int, int, int);
extern int data_0204c208;
void TailForwardTrackEntry(int param_1, int param_2, int param_3, int param_4) {
    Entity_Register(data_0204c208 + 0xc4 + param_1 * 0x184, param_2, param_3, param_4);
}
