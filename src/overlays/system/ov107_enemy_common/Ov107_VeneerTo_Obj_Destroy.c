/* Interworking tail-call veneer: reaches Obj_Destroy through the main-module veneer
 * func_02023ad0. */
extern int func_02023ad0();
int Ov107_VeneerTo_Obj_Destroy(int obj) {
    return func_02023ad0(obj);
}
