/* Whether the second argument equals the global halfword (IsArgEqualGlobalHalf4); the first is
 * ignored. */

extern void IsArgEqualGlobalHalf4();
void Ov022_ForwardArg1(int arg0, int arg1) { IsArgEqualGlobalHalf4(arg1); }
