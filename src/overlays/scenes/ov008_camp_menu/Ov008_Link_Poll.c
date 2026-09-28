/* Polls the link service instance. Returns the word it reads at +0x28 of the object. */

extern int data_ov008_02090f24[];
extern int Obj_GetWord28(int);
int Ov008_Link_Poll(void)
{
    return Obj_GetWord28(data_ov008_02090f24[1]);
}
