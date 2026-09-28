#pragma thumb on
/* Ov023_Window_OpenMessages -- load a sub-panel resource into slot @+0x1a24, ov023
 * (Msg_OpenContainerAndReadHeader, mode 0xd). */
extern void *Msg_OpenContainerAndReadHeader(void *desc, int mode);
void Ov023_Window_OpenMessages(char *obj, void *desc) {
    *(void **)(obj + 0x1a24) = Msg_OpenContainerAndReadHeader(desc, 0xd);
}
