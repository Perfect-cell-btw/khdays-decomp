extern unsigned short LoadGlobalU16At0(void);
extern void GFXi_EnqueueCommand(int a, int b, int c, int d);

void Gfx_EnqueueSurface(int param_1) {
    int mode = (LoadGlobalU16At0() & 2) == 0 ? 0xb : 10;
    GFXi_EnqueueCommand(mode, 0, *(int *)(param_1 + 0x94) + 0xc,
                  *(int *)(*(int *)(param_1 + 0x94) + 8));
}
