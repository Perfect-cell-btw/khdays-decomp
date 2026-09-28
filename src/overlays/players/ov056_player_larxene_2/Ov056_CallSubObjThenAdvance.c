/* Forwards the global command to the effect stream, then runs the group callback. */

extern void Ov022_ForwardToNodeHandler();
extern void Ov056_InvokeGroupCallback();

void Ov056_CallSubObjThenAdvance(int this_) {
    Ov022_ForwardToNodeHandler(*(int *)(this_ + 0x2644));
    Ov056_InvokeGroupCallback(this_);
}
