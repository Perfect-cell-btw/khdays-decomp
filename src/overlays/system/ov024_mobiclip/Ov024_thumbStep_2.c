/* Return whether Ov024_IsRunning reports success (nonzero). */
extern int Ov024_IsRunning(int arg);
int Ov024_thumbStep_2(int param_1) {
    return Ov024_IsRunning(param_1) != 0;
}
