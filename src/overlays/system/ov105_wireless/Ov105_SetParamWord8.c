/* Store param_1 into the field at (&data_ov105_020c0580 + 8). */
extern int data_ov105_020c0580;
void Ov105_SetParamWord8(int param_1) {
    *(int *)((char *)&data_ov105_020c0580 + 8) = param_1;
}
