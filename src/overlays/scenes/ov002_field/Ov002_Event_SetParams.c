/* Stores the event's id and argument and clears its counter. */

extern int data_ov002_0207fa14;

void Ov002_Event_SetParams(int arg0, int arg1) {
    int base = *(int *)&data_ov002_0207fa14;
    *(short *)(base + 0xa) = arg0;
    *(short *)(base + 0xc) = 0;
    *(short *)(base + 0xe) = arg1;
}
