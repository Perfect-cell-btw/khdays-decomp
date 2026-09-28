/* Script command: reads two int operands and creates the actor from the marker. */

extern int ScriptVm_ReadOperandInt();
extern int Ov002_CreateActorFromMarker();

int Ov002_ScriptCmd_CreateActorFromMarker(int arg0, int arg1) {
    int a = ScriptVm_ReadOperandInt(arg0, arg1);
    int b = ScriptVm_ReadOperandInt(arg0, arg1 + 8);
    Ov002_CreateActorFromMarker(a, b);
    return 1;
}
