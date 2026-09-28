/* Draws the result scene and each player's character models (rotating the winners), accumulating
 * their stats. */

extern void Scene_DrawNode(void *p);
extern void Ov003_AccumulateThreeGlobalStats(int i, int v);
extern void Ov003_ApplyRotationToLayers(int i, int v);

void Ov003_UpdateLayers(unsigned short *param_1) {
    int *p1000;
    unsigned short *puVar1;
    unsigned short *puVar2;
    unsigned short *puVar3;
    unsigned short *puVar4;
    int iVar5;

    Scene_DrawNode(param_1 + 0x84);
    iVar5 = 0;
    if (0 < (int)(unsigned int)*param_1) {
        puVar1 = param_1 + 0x108;
        puVar2 = param_1 + 0x318;
        puVar3 = param_1 + 0x528;
        puVar4 = param_1 + 0x738;
        p1000 = (int *)((char *)param_1 + 0x1000);
        do {
            Ov003_AccumulateThreeGlobalStats(iVar5, ((int *)param_1)[iVar5 + 0x5d4]);
            if (((int *)param_1)[iVar5 + 0xb] == 3) {
                Ov003_ApplyRotationToLayers(iVar5, p1000[0x1d8]);
            }
            Scene_DrawNode(puVar1);
            Scene_DrawNode(puVar2);
            Scene_DrawNode(puVar3);
            if (((int *)param_1)[iVar5 + 0x4a4] != 0) {
                Scene_DrawNode(puVar4);
            }
            iVar5 = iVar5 + 1;
            puVar1 = puVar1 + 0x84;
            puVar2 = puVar2 + 0x84;
            puVar3 = puVar3 + 0x84;
            puVar4 = puVar4 + 0x84;
        } while (iVar5 < (int)(unsigned int)*param_1);
    }
}
