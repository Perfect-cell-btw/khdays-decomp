/* Push this enemy's animation argument into its +0x2644 part record and the record at +0x30,
 * then run the follow-up pass in Ov062_InvokeBothGroupCallbacks. */
extern void Ov022_ForwardToNodeHandler(int part, int a);
extern void Ov062_InvokeBothGroupCallbacks(int this_);

void Ov062_PushAnimArg(int this_, int a) {
    Ov022_ForwardToNodeHandler(*(int *)(this_ + 0x2000 + 0x644), a);
    Ov022_ForwardToNodeHandler(*(int *)(this_ + 0x2000 + 0x644) + 0x30, a);
    Ov062_InvokeBothGroupCallbacks(this_);
}
