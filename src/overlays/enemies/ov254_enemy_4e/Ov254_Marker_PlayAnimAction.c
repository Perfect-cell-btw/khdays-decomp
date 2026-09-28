/* Store param_2 at param_1+0xc and mark the linked object's state byte (+0x1c7) as 3. */
void Ov254_Marker_PlayAnimAction(int param_1, int param_2) {
    *(unsigned char *)(param_1 + 0xc) = (unsigned char)param_2;
    *(unsigned char *)(*(int *)param_1 + 0x1c7) = 3;
}
