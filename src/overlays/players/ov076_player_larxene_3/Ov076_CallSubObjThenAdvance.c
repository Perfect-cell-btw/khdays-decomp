/* Forwards the global command to the effect stream, then runs the group callback. */

extern void Ov022_ForwardToNodeHandler();
extern void Ov076_InvokeGroupCallback();

void Ov076_CallSubObjThenAdvance(int this_) {
    Ov022_ForwardToNodeHandler(*(int *)(this_ + 0x2644));
    Ov076_InvokeGroupCallback(this_);
}
