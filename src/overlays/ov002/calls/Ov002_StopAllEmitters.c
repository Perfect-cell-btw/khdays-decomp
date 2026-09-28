extern int *data_ov002_0207f628;

extern void Tween_Clear(void *pEmitter);

/* Stop every effect emitter and clear the per-slot counters. Both emitter
 * banks hold ten entries of 0x1c bytes and are stopped in step. */
void Ov002_StopAllEmitters(void)
{
    int *pOwner;
    int i;
    char *pFirst;
    char *pSecond;

    pOwner = data_ov002_0207f628;
    if (pOwner == 0) {
        return;
    }

    pOwner[0xfec / 4] = 0;

    pFirst = (char *)pOwner + 0xb28;
    pSecond = (char *)pOwner + 0xc40;

    for (i = 0; i < 10; i++) {
        Tween_Clear(pFirst);
        Tween_Clear(pSecond);
        pOwner[i + 0x54 / 4] = 0;
        pFirst += 0x1c;
        pSecond += 0x1c;
    }

    pOwner[0xdb8 / 4] = 0;
    pOwner[0xdbc / 4] = 0;
}
