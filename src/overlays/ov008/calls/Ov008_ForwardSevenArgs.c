/* Pass all seven arguments straight through to Ov008_MissionDrawTextRun. Named for the forwarding
 * only: the target is still an ASM stub, so there is no semantics to inherit yet. */

extern void Ov008_MissionDrawTextRun(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6);

void Ov008_ForwardSevenArgs(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6)
{
    Ov008_MissionDrawTextRun(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
}
