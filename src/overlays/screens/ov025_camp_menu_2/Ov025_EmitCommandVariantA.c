/* Requests a card stream command with the second argument set (CARDi_RequestStreamCommand). */

extern int CARDi_RequestStreamCommand();

int Ov025_EmitCommandVariantA(unsigned int arg0, unsigned int arg1, unsigned int arg2) {
    return CARDi_RequestStreamCommand(arg1, arg0, arg2, 0, 0, 1, 8, 10, 2);
}
