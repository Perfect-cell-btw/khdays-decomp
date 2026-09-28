/* Set +0x30=0x14000, then dispatch via c634. */
extern int SetIndexedSlot(int, int, void *);
extern int Ov245_FlightTick(int);
int Ov245_AiEnterFlight(int param_1) {
    *(int *)(*(int *)(param_1 + 4) + 0x30) = 0x14000;
    return SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov245_FlightTick);
}
