/* Forward to Ov023_Cmd_SpawnEntityFollower and report success. */
extern void Ov023_Cmd_SpawnEntityFollower(int arg, char *args);
int Ov023_CmdEntry_SpawnEntityFollower(int param_1, char *args) {
    Ov023_Cmd_SpawnEntityFollower(param_1, args);
    return 1;
}
