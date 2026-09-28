/* Offset of entry index of the resource. */

int Ov002_Res_GetEntryOffset(int arg0, int index) {
    return *(int *)(*(int *)(arg0 + 8) + index * 4 + 0x10);
}
