/* Allocate a 0x1c-byte object, initialise it via 020cb5c8 and return it. */
extern int CallocInstance(int a);
extern void Ov107_TaskRestartWith5f0(int a);
int Ov107_CreateRestartTask(void) {
    int obj = CallocInstance(0x1c);
    Ov107_TaskRestartWith5f0(obj);
    return obj;
}
