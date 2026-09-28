/* Forward to Ov024_SetFinished and return 0. */
extern void Ov024_SetFinished(int arg);
int Ov024_thumbStep(int param_1) {
    Ov024_SetFinished(param_1);
    return 0;
}
