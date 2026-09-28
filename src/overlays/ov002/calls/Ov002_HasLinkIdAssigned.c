extern int Ov002_BuildSessionCommand(int kind, int *out);

int Ov002_HasLinkIdAssigned(void) {
    int out;
    return Ov002_BuildSessionCommand(4, &out) != 0xffff;
}
