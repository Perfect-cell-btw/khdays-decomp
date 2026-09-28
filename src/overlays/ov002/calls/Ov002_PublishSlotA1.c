extern int Ov002_RunShutdownHook();
extern int Ov002_PublishSlotValueA();

void Ov002_PublishSlotA1(int arg0) {
    if (Ov002_RunShutdownHook(arg0) != 0) {
        return;
    }
    Ov002_PublishSlotValueA(1, arg0);
}
