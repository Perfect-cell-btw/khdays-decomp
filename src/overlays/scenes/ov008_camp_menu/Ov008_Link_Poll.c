/* Polls the link service instance. */

extern int data_ov008_02090f24[];
extern void Obj_GetWord28(int);
void Ov008_Link_Poll(void)
{
    Obj_GetWord28(data_ov008_02090f24[1]);
}
