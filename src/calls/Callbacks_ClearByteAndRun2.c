extern int Callbacks_SetByte();
extern int Callbacks_Run();

void Callbacks_ClearByteAndRun2(void) {
    Callbacks_SetByte(0);
    Callbacks_Run(2);
}
