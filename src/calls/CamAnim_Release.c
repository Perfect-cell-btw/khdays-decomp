extern int CamAnim_IsActive(void *p);
extern void CamAnim_FreePlayer(void *p);
extern void ResSlot_Release(void *p);

void CamAnim_Release(void **p)
{
    if (CamAnim_IsActive(p) != 0) {
        CamAnim_FreePlayer(p[2]);
        ResSlot_Release(p[1]);
    }
    p[0] = 0;
}
