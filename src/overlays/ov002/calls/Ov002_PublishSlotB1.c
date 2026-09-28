/* Unless shut down, publishes flag B1. */

extern int Ov002_RunShutdownHook();
extern int Ov002_PublishSlotValueB();

void Ov002_PublishSlotB1(int arg0) {
    if (Ov002_RunShutdownHook(arg0) != 0) {
        return;
    }
    Ov002_PublishSlotValueB(1, arg0 != 0);
}
