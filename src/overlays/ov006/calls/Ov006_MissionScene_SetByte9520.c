/* Stores byte +0x9520 of the mission scene. */

/* Store a byte at +0x9520 of the ov006 global object. */
extern int data_ov006_02056664;
void Ov006_MissionScene_SetByte9520(int param_1) {
    *(signed char *)(data_ov006_02056664 + 0x9520) = param_1;
}
