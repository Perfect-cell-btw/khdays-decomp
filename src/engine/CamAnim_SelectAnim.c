/* Selects the animation in the resource and binds it to the player. */

extern int NNS_G3dGetAnmByIdx(void *p, int idx);
extern int initObjAndDispatch(void *p, int a);
extern int Obj_SetIndirectWord(void *p, int a);

int CamAnim_SelectAnim(void **p, int idx)
{
    int v = NNS_G3dGetAnmByIdx(((void **)p[1])[3], idx);
    initObjAndDispatch(p[2], v);
    return Obj_SetIndirectWord(p, 0);
}
