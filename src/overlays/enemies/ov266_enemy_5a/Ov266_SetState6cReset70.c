void Ov266_SetState6cReset70(char *obj) {
    *(int *)(obj + 0x6c) = 1;
    *(int *)(obj + 0x70) = -1;
}
