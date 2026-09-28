/* Leaves the sub-menu unless already out, then returns the next step. */

extern int Ov008_IsSceneState0(void);
extern void Ov008_MissionLeaveSubMenu(void);
extern void Ov008_WaitSceneState0(void);
void *Ov008_EnsureLeftSubMenu(void)
{
    if (Ov008_IsSceneState0() == 0) {
        Ov008_MissionLeaveSubMenu();
    }
    return Ov008_WaitSceneState0;
}
