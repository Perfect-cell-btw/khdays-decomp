/* Forward to Ov023_Cmd_SpawnEntityFollower and report success. */
extern void Ov023_Cmd_SpawnEntityFollower(int arg);
int Ov023_CmdEntry_SpawnEntityFollower(int param_1) {
    Ov023_Cmd_SpawnEntityFollower(param_1);
    return 1;
}
