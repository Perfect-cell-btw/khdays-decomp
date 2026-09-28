/* Releases the mission scene instance; in link mode also releases the wireless overlay and resets.
 */

extern char *data_ov008_02090fa8;
extern void func_02023ad0(int arg0);
extern void Overlay105_Release(void);
extern void func_02003948(int arg0);

void Ov008_MissionScene_Release(void)
{
    func_02023ad0(*(int *)data_ov008_02090fa8);

    if (*(int *)(data_ov008_02090fa8 + 4) == 2) {
        Overlay105_Release();
        func_02003948(-2);
    }
}
