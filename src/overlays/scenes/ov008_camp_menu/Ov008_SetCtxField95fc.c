/* Enables both screen halves and stores the menu state's word at +0x95fc. */

extern void Ov008_EnableBothHalves(void);
extern int data_ov008_02090f04[];
void Ov008_SetCtxField95fc(int value)
{
    Ov008_EnableBothHalves();
    *(int *)(data_ov008_02090f04[1] + 0x95fc) = value;
}
