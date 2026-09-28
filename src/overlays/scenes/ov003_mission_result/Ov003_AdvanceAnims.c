/* Advances the result characters' animations, rebinding each finished one to its idle or victory
 * pose. */

extern unsigned int BuildSlotMask(int p, int a);
extern void BindAnimTrack(int a, int b, int c, int d);
extern void Sequence_UpdateTracks(void *p, int a);

void Ov003_AdvanceAnims(unsigned short *param_1) {
    unsigned int uVar1;
    int iVar2;
    unsigned short *puVar3;
    unsigned short *puVar4;
    unsigned short *puVar5;

    if (*(int *)(param_1 + 0x2a) != 1) {
        return;
    }
    iVar2 = 0;
    if (0 < (int)(unsigned int)*param_1) {
        puVar3 = param_1 + 0x528;
        puVar4 = param_1 + 0xb60;
        puVar5 = param_1 + 0x738;
        do {
            uVar1 = BuildSlotMask((int)puVar3, 0x1000);
            if ((uVar1 & 1) != 0) {
                if (((int *)param_1)[iVar2 + 0xb] == 0) {
                    BindAnimTrack((int)puVar3, 0, (int)puVar4, 2);
                    if (((int *)param_1)[iVar2 + 0x4a4] != 0) {
                        BindAnimTrack((int)puVar5, 0, (int)(puVar5 + 0x70), 2);
                    }
                } else {
                    BindAnimTrack((int)puVar3, 0, (int)puVar4, 5);
                    if (((int *)param_1)[iVar2 + 0x4a4] != 0) {
                        BindAnimTrack((int)puVar5, 0, (int)(puVar5 + 0x70), 5);
                    }
                }
            }
            Sequence_UpdateTracks(puVar3, 0x1000);
            if (((int *)param_1)[iVar2 + 0x4a4] != 0) {
                Sequence_UpdateTracks(puVar5, 0x1000);
            }
            puVar3 = puVar3 + 0x84;
            puVar4 = puVar4 + 0x12;
            puVar5 = puVar5 + 0x84;
            iVar2 = iVar2 + 1;
        } while (iVar2 < (int)(unsigned int)*param_1);
    }
}
