/* Delivers the event, tagging it 0x1000 when not from the local player. */

extern int Ov002_DeliverEventUnlessMuted();

int Ov002_DeliverEventLocalFlag(int arg0, int arg1) {
    if (arg0 == 0) {
        arg1 |= 0x1000;
    }
    return Ov002_DeliverEventUnlessMuted(arg1);
}
