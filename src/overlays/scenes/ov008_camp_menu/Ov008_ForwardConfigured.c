/* Forwards to the object's sub-object at +0x1c with the fixed mode (2, 4). */

extern void Obj_ForwardToSub1c(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5);

void Ov008_ForwardConfigured(int arg0, int arg1, int arg2, int arg3)
{
    Obj_ForwardToSub1c(arg0, arg2, arg3, 2, 4, arg1);
}
