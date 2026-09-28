/* Forwards the global command to the effect stream, then runs the group callback. */

extern void Ov022_ForwardToNodeHandler();
extern void Ov076_InvokeGroupCallback();

void Ov076_CallSubObjThenAdvance(int this_, int a) {
    Ov022_ForwardToNodeHandler(*(int *)(this_ + 0x2644), a);
    Ov076_InvokeGroupCallback(this_);
}
