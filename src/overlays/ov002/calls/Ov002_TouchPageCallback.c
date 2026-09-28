extern int Ov002_RunShutdownHook();
extern int Ov002_PublishSlotValueA();

void Ov002_TouchPageCallback(int arg0) {
    if (Ov002_RunShutdownHook(arg0) != 0) {
        return;
    }
    Ov002_PublishSlotValueA(0, arg0);
}
