/* Return whether Ov023_StepDialog reports empty (returned zero). */
extern int Ov023_StepDialog(int arg);
int Ov023_CmdWaitDialog(int param_1) {
    return Ov023_StepDialog(param_1) == 0;
}
