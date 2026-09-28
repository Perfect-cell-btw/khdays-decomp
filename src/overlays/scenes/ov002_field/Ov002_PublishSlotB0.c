/* Unless shut down, publishes flag B0. */

extern int Ov002_RunShutdownHook();
extern int Ov002_PublishSlotValueB();

void Ov002_PublishSlotB0(int arg0) {
    if (Ov002_RunShutdownHook(arg0) != 0) {
        return;
    }
    Ov002_PublishSlotValueB(0, arg0 != 0);
}
