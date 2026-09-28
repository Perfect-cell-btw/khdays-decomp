/* NitroSystem: inits the frame palette VRAM manager with the size and optionally installs it as the
 * default allocator. */

extern int data_02047364[];
extern void *data_020423f4;
extern void *data_020423f8;
extern void NNS_GfdResetFrmPlttVramState(int value);
extern void func_020111c0(void);
extern void NNS_GfdFreeFrmPlttVram(void);

void NNS_GfdInitFrmPlttVramManager(int value, int install_callbacks) {
    data_02047364[2] = value;
    NNS_GfdResetFrmPlttVramState(value);

    if (install_callbacks != 0) {
        data_020423f4 = func_020111c0;
        data_020423f8 = NNS_GfdFreeFrmPlttVram;
    }
}
