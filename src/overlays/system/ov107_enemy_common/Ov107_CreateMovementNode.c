/* Allocate a 0x120-byte object, initialise it via 020c0dd0 and return it. */
extern int CallocInstance(int a);
extern void Ov107_InitMovementNode(int a);
int Ov107_CreateMovementNode(void) {
    int obj = CallocInstance(0x120);
    Ov107_InitMovementNode(obj);
    return obj;
}
