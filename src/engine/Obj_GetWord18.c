/* Returns the word at a fixed offset of the object. */

int Obj_GetWord18(char *pP){
    int *p = (int *)pP; return p[6]; }
