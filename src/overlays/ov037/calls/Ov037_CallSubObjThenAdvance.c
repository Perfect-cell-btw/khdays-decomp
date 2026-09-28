extern void Ov022_ForwardToNodeHandler();
extern void Ov037_InvokeGroupCallback();

void Ov037_CallSubObjThenAdvance(int this_) {
    Ov022_ForwardToNodeHandler(*(int *)(this_ + 0x2644));
    Ov037_InvokeGroupCallback(this_);
}
