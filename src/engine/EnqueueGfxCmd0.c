extern int GFXi_EnqueueCommand();

int EnqueueGfxCmd0(int arg0, int arg1, int arg2) {
    return GFXi_EnqueueCommand(0, arg1, arg0, arg2);
}
