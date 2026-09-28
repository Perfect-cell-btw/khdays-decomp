extern int NNS_G3dGetAnmByIdx(void *p);
extern int initObjAndDispatch(void *p, int a);
extern int Obj_SetIndirectWord(void *p, int a);

int CamAnim_SelectAnim(void **p)
{
    int v = NNS_G3dGetAnmByIdx(((void **)p[1])[3]);
    initObjAndDispatch(p[2], v);
    return Obj_SetIndirectWord(p, 0);
}
