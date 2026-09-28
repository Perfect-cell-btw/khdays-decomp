extern unsigned int Ov022_StepIdleActor(unsigned int *p);
extern unsigned int Ov022_SteerIdleByAim(unsigned int *p, unsigned int a);
extern void func_ov022_020acf14(unsigned int *p, int a);

struct bits_020a37d0 {
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char rest : 6;
};

unsigned int func_ov022_020a37d0(unsigned int *param_1) {
    unsigned int uVar1 = Ov022_StepIdleActor(param_1);
    int iVar2;
    if (uVar1 == 0) {
        uVar1 = Ov022_SteerIdleByAim(param_1, param_1[0xaaf]);
    }
    iVar2 = (*(int (**)(unsigned int *))(param_1 + 0x19a))(param_1);
    ((struct bits_020a37d0 *)(param_1 + 0x1a5))->b1 = iVar2;
    if (((struct bits_020a37d0 *)(param_1 + 0x1a5))->b1 != 0 && param_1[0x1af] == 1) {
        func_ov022_020acf14(param_1, 0);
    }
    return uVar1;
}
